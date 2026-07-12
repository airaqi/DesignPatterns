#include "program_node_expr_logical_not.hpp"
#include <format>
#include <string>

NotNode::NotNode(Token::Ptr token, ExprNode::Ptr e) : LogicalNode(token, e, e) {}

NotNode::Ptr NotNode::create(Token::Ptr token, ExprNode::Ptr e)
{
    return NotNode::Ptr(new NotNode(token, e));
}

void NotNode::jumping(int t, int f) 
{
    rhs()->jumping(f, t);
}

std::string NotNode::to_string(std::string prefix) const
{
    return std::format("{}{} {}", prefix, op()->to_string(), rhs()->to_string());
}

std::string NotNode::print(std::string prefix) const
{
    return std::format("{}[Not ({}, {})]", prefix, op()->to_string(), rhs()->to_string());
}
