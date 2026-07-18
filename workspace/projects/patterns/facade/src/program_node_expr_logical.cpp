#include "program_node_expr_logical.hpp"
#include "compiler_token_word_type.hpp"
#include "plog/Log.h"
#include "program_node_expr_temp.hpp"
#include <format>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

LogicalNode::LogicalNode(Token::Ptr token, ExprNode::Ptr l, ExprNode::Ptr r) : 
    ExprNode(token, Type::Null),
    _lhs(l),
    _rhs(r) 
{
    //std::cout << "LogicalNode::LogicalNode(" << token << ", " << l << ", " << r << ")\n";

    //type(this->check(lhs()->type(), rhs()->type()));
    //if (type() == Type::Null)
        //error("type error");
}

LogicalNode::Ptr LogicalNode::create(Token::Ptr tok, ExprNode::Ptr l, ExprNode::Ptr r) 
{
    LogicalNode::Ptr instance = std::make_shared<LogicalNode>(tok, l, r);
    instance->initialize();
    return instance;
}

void LogicalNode::initialize() 
{
    PLOGD << "()";
    Type::Ptr t = this->check(lhs()->type(), rhs()->type());
    PLOGD << " - t check: " << t;
    type(this->check(lhs()->type(), rhs()->type()));
    PLOGD << " - type: " << type();
    if (*type() == *Type::Null)
        error(std::format("type error: {} cannot be null", this->to_string()));
}

void LogicalNode::lhs(ExprNode::Ptr l) { _lhs = l; }
void LogicalNode::rhs(ExprNode::Ptr r) { _rhs = r; }

ExprNode::Ptr LogicalNode::lhs() const { return _lhs; }
ExprNode::Ptr LogicalNode::rhs() const { return _rhs; }

Type::Ptr LogicalNode::check(Type::Ptr l, Type::Ptr r)
{
    PLOGD << "(" << l << ", " << r << ")";

    if (*l == *Type::Bool && *r == *Type::Bool)
        return Type::Bool;
    else
        return Type::Null;
}

ExprNode::Ptr LogicalNode::gen()
{
    int f = newlabel();
    int a = newlabel();
    TempNode::Ptr temp = TempNode::create(type());
    this->jumping(0, f);
    emit(static_cast<std::ostringstream>(std::ostringstream() << temp->to_string() << " = true").str());
    emit(static_cast<std::ostringstream>(std::ostringstream() << "goto L" << a).str());
    emitlabel(f);
    emit(static_cast<std::ostringstream>(std::ostringstream() << temp->to_string() << " = false").str());
    emitlabel(a);
    return temp;
}

std::string LogicalNode::to_string(std::string prefix) const
{
    return std::format("{} {}", lhs()->to_string(), rhs()->to_string());
}

std::string LogicalNode::print(std::string prefix) const
{
    return std::format("{}[Logical({}, {})]", prefix, lhs()->print(), rhs()->print());
}
