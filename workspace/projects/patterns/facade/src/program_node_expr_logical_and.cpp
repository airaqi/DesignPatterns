#include "program_node_expr_logical_and.hpp"
#include "compiler_token.hpp"
#include "program_node_expr_logical.hpp"
#include <memory>

AndNode::AndNode(Token::Ptr token, ExprNode::Ptr l, ExprNode::Ptr r) :
    LogicalNode(token, l, r) {}

AndNode::Ptr AndNode::create(Token::Ptr token, ExprNode::Ptr l, ExprNode::Ptr r)
{
    return std::make_shared<AndNode>(token, l, r);
}

void AndNode::jumping(int t, int f)
{
    int label = f != 0 ? f : newlabel();
    lhs()->jumping(0, label);
    rhs()->jumping(t, f);
    if (f == 0)
        emitlabel(label);
}
