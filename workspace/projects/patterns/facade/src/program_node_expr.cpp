#include "program_node_expr.hpp"
#include "compiler_token_word_type.hpp"
#include "program_node_expr_variable.hpp"
#include <format>
#include <iostream>
#include <memory>
#include <ostream>
#include <sstream>
#include <string>

int ProgNode::_next_id = 0;
int ProgNode::_labels = 0;
const ExprNode::Ptr ExprNode::Null = ExprNode::create(nullptr, nullptr);

ExprNode::ExprNode(Token::Ptr token, Type::Ptr type) : _op(token), _type(type) {}

ExprNode::Ptr ExprNode::create(Token::Ptr tok, Type::Ptr t)
{
    return ExprNode::Ptr(new ExprNode(tok, t));
}


ExprNode::Ptr ExprNode::gen() 
{
    return ExprNode::Ptr(this);
}


ExprNode::Ptr ExprNode::reduce() 
{
    return ExprNode::Ptr(this);
}

void ExprNode::type(Type::Ptr t) { _type = t;}
Type::Ptr ExprNode::type() const { return _type; }

void ExprNode::op(Token::Ptr p) { _op = p; }
Token::Ptr ExprNode::op() const { return _op; }

void ExprNode::jumping(int t, int f)
{
    emitjumps(to_string(), t, f);
}

void ExprNode::emitjumps(std::string test, int t, int f) const
{
    if (t != 0 && f != 0) {
        emit(std::format("if {} goto L{}", test, t));
        emit(std::format("goto L{}", f));
    }
    else if (t != 0) 
        emit(std::format("if {} goto L{}", test, t));
    else if (f != 0)
        emit(std::format("if false {} goto L{}", test, f));
    // Otherwise Nothing since both t and f fall through
}

void ExprNode::getSourcePosition(int &l, int &i)
{
    l = line();
    i = index();
}


void ExprNode::add(ProgNode::Ptr node)
{
    if (isBlock())
        node->scope(ExprNode::Ptr(this));
    else 
        node->scope(scope());

    // make sure that all variables defined in scope
    if (node->isVariable())
    {
        VariableNode::Ptr var = std::dynamic_pointer_cast<VariableNode>(node);
        scope()->define(var->name(), var);
    }
    else
        _children.insert_or_assign(node->id(), node);
}


void ExprNode::remove(ProgNode::Ptr node)
{
    _children.clear();
}

const ProgNode& ExprNode::child(const int id) const 
{
    return *_children.at(id);
}


std::map<int, ProgNode::Ptr>::const_iterator ExprNode::begin() const noexcept
{
    return _children.begin();
}


std::map<int, ProgNode::Ptr>::const_iterator ExprNode::end() const noexcept
{
    return _children.end();
}

void ExprNode::traverse(CodeGenerator& generator)
{
    generator.visit(this);
}

bool ExprNode::isExpression()
{
    return true;
}


std::string ExprNode::to_string(std::string prefix) const
{
    return std::format("{}{}", prefix, op()->to_string());
}

std::string ExprNode::print(std::string prefix) const
{
    std::stringstream sout;
    std::string subfix = prefix + "  ";

    sout << prefix << "[Expr(" << std::format("{}, {}, {}", id(), op()->to_string(), type()->to_string()) << "): ";
    for (auto const& [key, value] : _children)
        sout << value->to_string(subfix) << ", ";
    sout << prefix << "]";
    return sout.str();    
}


bool ExprNode::equals(const ProgNode& that) const
{
    const ExprNode& th = dynamic_cast<const ExprNode&>(that);
    return (_op == th._op) && (_type == th._type) ;
/*    bool ret = true;*/
    /*for(auto& it : _children)*/
        /*ret = ret && it.second->equals(that.child(it.first));*/
    /*return (ret && line() == that.line() && index() == that.index());*/
}

bool ExprNode::operator==(const ProgNode& that) const { return equals(that); }
bool ExprNode::operator!=(const ProgNode& that) const { return !(*this == that); }

std::ostream& operator<<(std::ostream& out, const ExprNode& e)
{
    out << e.to_string();
    return out;
}

std::ostream& operator<<(std::ostream& out, const ExprNode::Ptr e)
{
    return operator<<(out, *e.get());
}
