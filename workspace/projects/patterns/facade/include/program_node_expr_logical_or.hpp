#ifndef __COMPILER_PROGRAM_NODE_EXPR_LOGICAL_OR_H__
#define __COMPILER_PROGRAM_NODE_EXPR_LOGICAL_OR_H__ 

#include "program_node_expr_logical.hpp"
#include <memory>
class OrNode : public LogicalNode
{
    public:
        typedef std::shared_ptr<OrNode> Ptr;

        OrNode(Token::Ptr, ExprNode::Ptr, ExprNode::Ptr);

    public:
        static Ptr create(Token::Ptr, ExprNode::Ptr, ExprNode::Ptr);

        virtual void jumping(int, int) override;

};

#endif /* ifndef __COMPILER_PROGRAM_NODE_EXPR_LOGICAL_OR_H__ */
