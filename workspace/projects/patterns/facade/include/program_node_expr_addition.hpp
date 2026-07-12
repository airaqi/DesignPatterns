#ifndef __COMPILER_PROGRAM_NODE_EXPR_ADDITION_H__
#define __COMPILER_PROGRAM_NODE_EXPR_ADDITION_H__ 

#include "program_node.hpp"
#include "program_node_expr.hpp"
#include <memory>

class AdditionNode : public ExprNode
{
    public:
        typedef std::shared_ptr<AdditionNode> Ptr;
    public:
        AdditionNode(ProgNode::Ptr lhs, ProgNode::Ptr rhs);

    public:
        static Ptr create(ProgNode::Ptr, ProgNode::Ptr);

        ProgNode::Ptr lhs() const;
        ProgNode::Ptr rhs() const;

        virtual void scope(ProgNode::Ptr) override;

        virtual std::string to_string(std::string = "") const override;

    private:
        ProgNode::Ptr         _lhs;
        ProgNode::Ptr         _rhs;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_EXPR_ADDITION_H__ */
