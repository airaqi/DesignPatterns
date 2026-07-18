#include "program_node_expr_logical_or.hpp"
#include "program_node_expr_logical.hpp"
#include <memory>

OrNode::OrNode(Token::Ptr token, ExprNode::Ptr lhs, ExprNode::Ptr rhs) :
    LogicalNode(token, lhs, rhs) {}

OrNode::Ptr OrNode::create(Token::Ptr token, ExprNode::Ptr lhs, ExprNode::Ptr rhs)
{
    return std::make_shared<OrNode>(token, lhs, rhs);
}

void OrNode::jumping(int t, int f)
{
    int label = t != 0 ? t : newlabel();
    lhs()->jumping(label, 0);
    rhs()->jumping(t, f);
    if (t == 0)
        emitlabel(label);
}
