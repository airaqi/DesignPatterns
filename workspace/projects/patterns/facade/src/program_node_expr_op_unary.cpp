#include "program_node_expr_op_unary.hpp"
#include <format>
#include <memory>
#include <string>

UnaryNode::UnaryNode(Token::Ptr token, ExprNode::Ptr e) : OpNode(token, Type::Null()), _expr(e) 
{
    type(Type::max(Type::Int(), expr()->type()));
    if (*type() == *Type::Null())
        error(std::format("type error: {} cannot be null", type()->to_string()));
}

UnaryNode::Ptr UnaryNode::create(Token::Ptr token, ExprNode::Ptr expr)
{
    return std::make_shared<UnaryNode>(token, expr);
}

void UnaryNode::expr(ExprNode::Ptr e) { _expr = e; }
ExprNode::Ptr UnaryNode::expr() const { return _expr; }

ExprNode::Ptr UnaryNode::gen() 
{
    return UnaryNode::create(op(), _expr->reduce());
}

std::string UnaryNode::to_string(std::string prefix) const
{
    return std::format("{}{} {}", prefix, op()->to_string(), expr()->to_string());
}

std::string UnaryNode::print(std::string prefix) const
{
    return std::format("{}[Unary({}, {})]", prefix, op()->print(), expr()->print());
}
