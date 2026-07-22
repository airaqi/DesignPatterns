#include "compiler_parser.hpp"
#include "compiler_env.hpp"
#include "compiler_token.hpp"
#include "compiler_token_num.hpp"
#include "compiler_token_word_type_array.hpp"
#include "plog/Log.h"
#include "program_node_expr_const.hpp"
#include "program_node_expr_id.hpp"
#include "program_node_expr_logical_and.hpp"
#include "program_node_expr_logical_not.hpp"
#include "program_node_expr_logical_or.hpp"
#include "program_node_expr_logical_rel.hpp"
#include "program_node_expr_op_access.hpp"
#include "program_node_expr_op_arith.hpp"
#include "program_node_expr_op_unary.hpp"
#include "program_node_stmt_break.hpp"
#include "program_node_stmt_do.hpp"
#include "program_node_stmt_else.hpp"
#include "program_node_stmt_seq.hpp"
#include "program_node_stmt_set.hpp"
#include "program_node_stmt_setelem.hpp"
#include "program_node_stmt_while.hpp"
#include <format>
#include <iostream>
#include <memory>
#include <ostream>
#include <sstream>

Parser::Parser(Scanner& scanner, ProgramNodeBuilder& builder) : 
    _scanner(scanner), 
    _builder(builder), 
    _look(_scanner.scan()),
    _top(Env::Null()),
    _used(0) {}


Parser::~Parser() {}

void Parser::move() {
    _look = _scanner.scan();
    PLOGD << "() _look : " << _look->print();
}

void Parser::error(std::string s) {
    throw std::runtime_error("ERROR: " + s + " (" + std::to_string(Scanner::line()) + ", " + std::to_string(Scanner::index()) + ")");
}

void Parser::match(Tag::Kind t) {
    PLOGD << "(" << Tag::to_string(t) << ") _look.tag: " << _look->print();
    if (_look->tag() == t) {
        move(); 
    } else {
        error("ERROR: Syntax error!");
    }
}


StmtNode::Ptr Parser::parse()
{
    PLOGD << "() look: " << _look->print();

    StmtNode::Ptr s = block();
    int begin = s->newlabel();
    int after = s->newlabel();
    s->emitlabel(begin);
    s->gen(begin, after);
    s->emitlabel(after);
    // PLOGD <<"s : " << s->print();
    return s;
}

StmtNode::Ptr Parser::block() 
{
    PLOGD << "()";

    match(Tag::CUBO);
    Env::Ptr savedEnv = _top;
    _top = Env::create(_top);
    decls();
    StmtNode::Ptr s = stmts();
    match(Tag::CUBC);
    _top = savedEnv;
    PLOGD << "s: " << s->print();
    return s;
}

void Parser::decls()
{
    while(_look->tag() == Tag::BASIC)
    {
        Type::Ptr typ = type();
        Token::Ptr tok = _look;
        match(Tag::ID); 
        match(Tag::SCLN);
        Id::Ptr id = Id::create(std::static_pointer_cast<Word>(tok), typ, _used);
        _top->put(tok, id);
        PLOGD << "type: " << typ->print() << " token: " << tok->print() << " _used: " << _used << "- top: " << _top->to_string();
        _used = _used + typ->width();
        // PLOGD << "<<<";
    }
}

Type::Ptr Parser::type()
{
    // TODO find a way to eleminate this cast
    Type::Ptr p = std::static_pointer_cast<Type>(_look);
    PLOGD << "_look: " << _look->print() << " p: " << p;
    match(Tag::BASIC);
    if (_look->tag() != Tag::SQBO)
        return p;
    else
        return dims(p);
}

Type::Ptr Parser::dims(Type::Ptr p) 
{
    match(Tag::SQBO);
    Token::Ptr tok = _look;
    match(Tag::NUM);
    match(Tag::SQBC);
    if (_look->tag() == Tag::SQBO)
        p = dims(p);
    PLOGD << "(" << p << ")";
    Array::Ptr arr = Array::create(std::static_pointer_cast<Num>(tok)->value(), p); 
    // PLOGD << "<<<";
    return arr;
}

StmtNode::Ptr Parser::stmts()
{
    PLOGD << "() - look: " << _look->print();
    if (_look->tag() == Tag::CUBC)
        return StmtNode::Null();
    else 
    {
        StmtNode::Ptr st = stmt(), sts = stmts();
        PLOGD << "- stmt: " << st->print() << " stmts: " << sts->print();
        return SeqNode::create(st, sts);
    }
}

StmtNode::Ptr Parser::stmt()    
{
    ExprNode::Ptr x;
    StmtNode::Ptr s, s1, s2;
    StmtNode::Ptr savedStmt;        // Save enclosing loops for breaks

    PLOGD << "() - look: " << _look->print();

    switch(_look->tag())
    {
        case Tag::SCLN:
            move();
            return StmtNode::Null();

        case Tag::IF:
            match(Tag::IF);
            match(Tag::PARO);
            x = boolean();
            match(Tag::PARC);
            s1 = stmt();
            if (_look->tag() != Tag::ELSE)
                return IfNode::create(x, s1);
            match(Tag::ELSE);
            s2 = stmt();
            return ElseNode::create(x, s1, s2);
        
        case Tag::WHILE:
            {
                PLOGD << "while : look: " << _look->print();
                WhileNode::Ptr  whileNode = WhileNode::create();
                savedStmt = StmtNode::Enclosing;
                StmtNode::Enclosing = whileNode;
                
                match(Tag::WHILE);
                match(Tag::PARO);
                x = boolean();
                match(Tag::PARC);
                s1 = stmt();
                whileNode->init(x, s1);
                StmtNode::Enclosing = savedStmt;        // reset enclosing statement
                return whileNode;
            }
        case Tag::DO:
            {
                DoNode::Ptr donode = DoNode::create();
                savedStmt = StmtNode::Enclosing;
                StmtNode::Enclosing = donode;

                match(Tag::DO);
                s1 = stmt();
                
                match(Tag::WHILE);
                match(Tag::PARO);
                x = boolean();
                match(Tag::PARC);
                match(Tag::SCLN);
                donode->init(s1, x);
                StmtNode::Enclosing = savedStmt;
                return donode;

            }
        case Tag::BREAK:
            match(Tag::BREAK);
            match(Tag::SCLN);
            return BreakNode::create();

        case Tag::CUBO:
            return block();

        default:
            return assign();
    }
}

StmtNode::Ptr Parser::assign()    
{
    PLOGD << "() _look: " << _look->print();

    StmtNode::Ptr st;
    Token::Ptr t = _look;
    match(Tag::ID);

    PLOGD << " - top: " << _top;
    //if (_top->prev() != nullptr)    PLOGD << "Parser::assign() - _top->prev(): " << _top->prev();

    Id::Ptr id = _top->get(t);

    if (id != nullptr) { PLOGD << " - id: " << id->print(); }
    if (id == nullptr) error(std::format("{} {}", t->to_string(), "undeclaired"));

    if (_look->tag() == Tag::ASGN)
    {
        PLOGD << " =";
        move();
        st = SetNode::create(id, boolean());
        PLOGD << " - st: " << st->print();
    }
    else 
    {
        // PLOGD << "accessNode";
        AccessNode::Ptr x = offset(id);
        match(Tag::ASGN);
        ExprNode::Ptr b = boolean();
        st = SetElemNode::create(x, b);
        PLOGD << "accessNode st = " << st;
    }
    match(Tag::SCLN);

    PLOGD << " - stmt: " << st->print();
    return st; 
}

ExprNode::Ptr Parser::boolean() 
{
    PLOGD << "() - I _look: " << _look->print();

    ExprNode::Ptr x = join();
    PLOGD << " - II _look: " <<_look->print();

    while(_look->tag() == Tag::OR)
    {
        Token::Ptr tok = _look;
        move();
        x = OrNode::create(tok, x, join());
    }
    return x; 
}

ExprNode::Ptr Parser::join()   
{
    PLOGD << "() _look: " << _look->print();

    ExprNode::Ptr x = equality();
    while(_look->tag() == Tag::AND)
    {
        Token::Ptr tok = _look;
        move();
        x = AndNode::create(tok, x, equality());
    }
    return x; 
}

ExprNode::Ptr Parser::equality()   
{
    PLOGD << "() _look: " << _look->print();

    ExprNode::Ptr x = rel();
    while (_look->tag() == Tag::EQ || _look->tag() == Tag::NE)
    {
        Token::Ptr tok = _look;
        move();
        x = RelNode::create(tok, x, rel());
    }
    return x; 
}

ExprNode::Ptr Parser::rel() 
{
    PLOGD << "() I _look: " << _look->print();

    ExprNode::Ptr x = expr();
    PLOGD << " - II look: " << _look->print();
    switch(_look->tag())
    {
        case Tag::LT:
        case Tag::LE:
        case Tag::GT:
        case Tag::GE:
            {
                PLOGD << " - III look: " << _look->print() << " x: " << x->print() << std::endl;
                Token::Ptr tok = _look;
                move();
                return RelNode::create(tok, x, expr());
            }
        default:
            return x;
    }
}

ExprNode::Ptr Parser::expr()
{
    PLOGD << "() - I _look: " << _look->print();

    ExprNode::Ptr x = term();
    // PLOGD << " - II _look: " << _look->print() << " plus: " << Tag::to_string(Tag::PLUS) << " x: " << x->print();
    while (_look->tag() == Tag::PLUS || _look->tag() == Tag::HYPH)
    {
        PLOGD << " - III _look: " << _look->print();
        Token::Ptr tok = _look;
        move();
        x = ArithNode::create(tok, x, term());
    }
    // PLOGD << " - IV x: " << x->print();
    return x; 
}

ExprNode::Ptr Parser::term()   
{
    PLOGD << "() - _look: " << _look->print();

    ExprNode::Ptr x = unary();
    while (_look->tag() == Tag::MULT || _look->tag() == Tag::SLSH)
    {
        Token::Ptr tok = _look;
        move();
        x = ArithNode::create(tok, x, unary());
    }
    return x; 
}

ExprNode::Ptr Parser::unary()   
{
    PLOGD << "() - _look: " << _look->print();

    if (_look->tag() == Tag::MINUS)
    {
        move();
        return UnaryNode::create(Word::minus(), unary());
    }
    else if (_look->tag() == Tag::NOT) 
    {
        Token::Ptr tok = _look;
        move();
        return NotNode::create(tok, unary());
    } 
    return factor();
}

ExprNode::Ptr Parser::factor()   
{
    PLOGD << "() - _look: " << _look->print();

    ExprNode::Ptr x = ExprNode::Null;
    switch (_look->tag()) 
    {
        case Tag::PARO:
            move();
            x = boolean();
            match(Tag::PARC);
            return x;

        case Tag::NUM:
            x = ConstNode::create(_look, Type::Int());
            move();
            return x;

        case Tag::REAL:
            x = ConstNode::create(_look, Type::Float());
            move();
            return x;

        case Tag::TRUE:
            x = ConstNode::True();
            move();
            return x;

        case Tag::FALSE:
            x = ConstNode::False();
            move();
            return x;

        case Tag::ID:
            {
                std::string s = _look->to_string();
                Id::Ptr id = _top->get(_look);
                if (id == nullptr) 
                    error(static_cast<std::ostringstream>(std::ostringstream() << s << " undeclared").str());
                move();
                if (_look->tag() != Tag::SQBO)
                    return id;
                else
                    return offset(id);
            }

        default:
            error("syntax error");
            return x;

    }
    return ExprNode::Null; 
}

AccessNode::Ptr Parser::offset(Id::Ptr a) 
{
    PLOGD << "(" << a << ") - _look: " << _look;

    ExprNode::Ptr i, w, t1, t2, loc;
    Type::Ptr typ = a->type();

    match(Tag::SQBO);
    i = boolean();
    match(Tag::SQBC);
    
    typ = std::static_pointer_cast<Array>(typ)->of();
    w = ConstNode::create(typ->width());
    t1 = ArithNode::create(Word::mult()->clone(), i, w);
    loc = t1;

    while (_look->tag() == Tag::SQBO)
    {
        match(Tag::SQBO);
        i = boolean();
        match(Tag::SQBC);

        typ = std::static_pointer_cast<Array>(typ)->of();
        w = ConstNode::create(typ->width());
        t1 = ArithNode::create(Word::mult()->clone(), i, w);
        t2 = ArithNode::create(Word::plus()->clone(), loc, t1);
        loc = t2;
    }

    return AccessNode::create(a, loc, typ); 
}
