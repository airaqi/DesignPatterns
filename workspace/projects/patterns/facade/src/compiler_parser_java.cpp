#include "compiler_parser_java.hpp"
#include "compiler_tag.hpp"
#include "compiler_token.hpp"
#include "compiler_token_word_type.hpp"
#include "program_node.hpp"
#include "program_node_expr_addition.hpp"
#include "program_node_expr_block.hpp"
#include "program_node_expr_multiply.hpp"
#include "program_node_expr_numeric.hpp"
#include "program_node_expr_string.hpp"
#include "program_node_expr_variable.hpp"
#include "program_node_expression.hpp"
#include "program_node_statement.hpp"
#include "program_node_stmt_assignment.hpp"
#include "program_node_stmt_condition.hpp"
#include <iostream>
#include <stdexcept>
#include <string>


ParserJava::ParserJava(Scanner& scanner, ProgramNodeBuilder& builder) 
    : Parser(scanner, builder) {}

ParserJava::~ParserJava() {}

ProgNode* ParserJava::parse(ProgNode* parent)
{
    std::cout << "Parser::parse " 
        << std::to_string(parent->id()) << " "
        //<< parent->scope()
        //<< "\n"
        //<< *parent
        << "\n";

    if (_scanner.eof())
        return parent;

    //Token t = _scanner.scan("parse " + std::to_string(parent->id()));
    move();
    Token t = _look;

    switch(t.tag())
    {
        case Tag::SCOLN:
            //std::cout << "SCOLN " << std::to_string(parent->id()) << "\n";
            return parent;

        case Tag::PARNO:
            {
                ExprNode *exp = _builder.newExpression();
                parent->add(exp);
                parse(exp);
                return exp;
            }

        case Tag::PARNC:
            return parent;

        case Tag::CURLO:
            {
                BlockNode* block = _builder.newBlock(nullptr);
                block->scope(parent->scope());
                parent->add(parse(block));
                break;
            }

        case Tag::CURLC:
                return parent;

        case Tag::DQUOT:
                {
                    if (_scanner.eof())
                        throw std::runtime_error("ERROR: closing double quote missing!");

                    std::string str;
                    for (Token n(Tag::NONE); n.tag() != Tag::DQUOT; n = _scanner.scan())
                        if (n.tag() == Tag::NTERM)
                            str += " " + n.name();
                        else if (n.tag() == Tag::NUM)
                            str += " " + std::to_string(n.value());
                    Token r(Tag::STRL, str);
                    _scanner.putback(r);
                    
                    break;
                }

        case Tag::NTERM:
            {
                //ProgramNode* var = get(t.name());
                ProgNode* var = parent->scope()->get(t.name());
                if (_scanner.eof()) 
                    throw std::runtime_error("ERROR: Expected operator!");

                Token k = _scanner.scan("Kind");

                // redefinition of variable
                if (var && (k.tag() == Tag::INT || k.tag() == Tag::FLOAT || k.tag() == Tag::DOUBLE || k.tag() == Tag::STR))
                    throw std::runtime_error("ERROR: redefinition of variable " + t.name());

                // reference of defined 
                else if (k.tag() == Tag::ASSGN || k.tag() == Tag::PLUSE || k.tag() == Tag::MULTI)
                {
                    _scanner.putback(t);
                    _scanner.putback(k);

                    ExprNode* exp = _builder.newExpression();
                    parent->add(exp);
                    parse(exp);
                    break;
                }

                // refernce Equality
                else if (k.tag() == Tag::EQUAL)
                {
                    _scanner.putback(t);
                    _scanner.putback(k);
                }

                // new definition
                else if (k.tag() == Tag::INT || k.tag() == Tag::FLOAT || k.tag() == Tag::DOUBLE || k.tag() == Tag::STR)
                {
                    var = _builder.newVariable(t.name(), k.tag());
                    parent->scope()->define(t.name(), var);
                    
                    Token n = _scanner.scan();
                    if (n.tag() == Tag::ASSGN)
                    {
                        _scanner.putback(t);
                        _scanner.putback(n);
                    }
                }

                else if (var)
                {
                    parent->add(var);
                    _scanner.putback(k);
                    break;
                }

                // reference to undefined variable
                else
                    throw std::runtime_error("ERROR: undefined variable " + t.name());

                break;
            }

        case Tag::INT:
        case Tag::DOUBLE:
        case Tag::FLOAT:
        case Tag::STR:
            {
                if (_scanner.eof())
                    throw std::runtime_error("ERROR: Expected variable identifier!");

                Token n = _scanner.scan("nTerm");
                if (n.tag() == Tag::NTERM) 
                {
                    _scanner.putback(t);
                    _scanner.putback(n);

                    ExprNode* exp = _builder.newExpression();
                    parent->add(exp);
                    parse(exp);
                }

                break;
            }

        case Tag::IF:
            {
                Token op = _scanner.scan();
                if (op.tag() != Tag::PARNO)
                    throw std::runtime_error("ERROR: Missing opening parentheses!");

                ProgNode *condExp = _builder.newExpression(),
                               *trueExp = _builder.newExpression(),
                               *falseExp = _builder.newExpression();

                ConditionNode *cond = _builder.newCondition(condExp, trueExp, falseExp);
                parent->add(cond);
                
                parse(condExp);
                parse(trueExp);
                parse(falseExp);

               break;
            }

        case Tag::ASSGN:
            {
                if (_scanner.eof())
                    throw std::runtime_error("ERROR: left hand side missing!");

                Token lhs = _scanner.scan("lhs");
                //ProgramNode *variable = get(lhs.name());
                ProgNode *variable = parent->scope()->get(lhs.name());
                if (lhs.tag() == Tag::NTERM)
                {
                    ExprNode *exp = _builder.newExpression();
                    AssignmentNode *asn = _builder.newAssignment(variable, exp);
                    //std::cout << *asn << "\n";
                    parent->add(asn);
                    parse(exp);
                }
                break;
            }

        case Tag::PLUSE:
            {
                if (_scanner.eof())
                    throw std::runtime_error("ERROR: left hand side missing");

                Token lhs = _scanner.scan("add lhs");
                ProgNode* lhsExp;
                if (lhs.tag() == Tag::NTERM)
                     lhsExp = parent->scope()->get(lhs.name());
                else if (parent->isExpression())
                    lhsExp = parent;
                else 
                    break;

                ExprNode *exp = _builder.newExpression();
                AdditionNode *add = _builder.newAddition(lhsExp, exp);
                parent->add(add);
                parse(exp);
            }

        case Tag::MULTI:
            {
                if (_scanner.eof())
                    throw std::runtime_error("ERROR: left hand side missing");

                Token lhs = _scanner.scan("add lhs");
                if (lhs.tag() == Tag::NTERM)
                {
                    ProgNode *var = parent->scope()->get(lhs.name());
                    ExprNode *exp = _builder.newExpression();
                    parse(exp);
                    MultiplicationNode *mult = _builder.newMultiplication(var, exp);
                    parent->add(mult);
                    parse(exp);
                }

                 break;
            }

        case Tag::EQUAL:
            {
                Token lhs = _scanner.scan();
                
                //ProgramNode* var = get(lhs.name());
                ProgNode* var = parent->scope()->get(lhs.name());
                ProgNode *exp = _builder.newExpression();
                exp->scope(parent->scope());
                parse(exp);

                EqualNode* node = _builder.newEqual(var, exp);
                parent->add(node);
                return parent;

                break;
            }

        case Tag::NUM:
        case Tag::REAL:
            {
                NumericNode *num = _builder.newNumeric(t.value());
                parent->add(num);
                return parent;
            }

        case Tag::STRL:
            {
                //std::cout << "STRL " << parent << "\n";
                StringNode* node = _builder.newStringLiteral(t.name());
                parent->add(node);
                return parent;
            }


        default:
            throw std::runtime_error(
                    "ERROR: syntax error! near (" 
                    + std::to_string(Scanner::line()) + ", " 
                    + std::to_string(Scanner::index()) + ") "
                    + t.name() + "..."
                    );
    }

    return parse(parent);
}

BlockNode* ParserJava::block(ProgNode* parent)
{
    match(Tag::CURLO);

    BlockNode *blockNode = _builder.newBlock(&_look);
    decls(blockNode);
    StmtNode* s = stmts();

    blockNode->add(s);
    
    return blockNode;
}

void ParserJava::decls(ProgNode* parent)
{
    while(_look.tag() == Tag::TERM)
    {
        Type *typ = type();
        Token &t = _look;
        match(Tag::ID); 
        match(Tag::SCOLN);
    }
}

Type* ParserJava::type()
{
    // TODO find a way to eleminate this cast
    Type *p = static_cast<Type*>(&_look);
    match(Tag::TERM);
    return p;
}

Type*               ParserJava::dims(Type* p)   { return nullptr; }

StmtNode*      ParserJava::stmts()    { return nullptr; }

StmtNode*      ParserJava::stmt()    { return nullptr; }

StmtNode*      ParserJava::assign()    { return nullptr; }

ExprNode*     ParserJava::boolean()   { return nullptr; }

ExprNode*     ParserJava::join()   { return nullptr; }

ExprNode*     ParserJava::equality()   { return nullptr; }

ExprNode*     ParserJava::rel()   { return nullptr; }

ExprNode*     ParserJava::expr()   { return nullptr; }

ExprNode*     ParserJava::term()   { return nullptr; }

ExprNode*     ParserJava::unary()   { return nullptr; }

ExprNode*     ParserJava::factor()   { return nullptr; }


