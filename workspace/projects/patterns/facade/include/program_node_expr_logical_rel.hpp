#ifndef __COMPILER_PROGRAM_NODE_EXPR_LOGICAL_REL_H__
#define __COMPILER_PROGRAM_NODE_EXPR_LOGICAL_REL_H__ 

#include "program_node_expr_logical.hpp"
#include <memory>
class RelNode : public LogicalNode
{
    public:
        typedef std::shared_ptr<RelNode> Ptr;

        RelNode(Token::Ptr, ExprNode::Ptr, ExprNode::Ptr);

    public:
        static Ptr create(Token::Ptr, ExprNode::Ptr, ExprNode::Ptr);

        virtual Type::Ptr check(Type::Ptr, Type::Ptr) override;
        virtual void jumping(int, int) override;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_EXPR_LOGICAL_REL_H__ */
