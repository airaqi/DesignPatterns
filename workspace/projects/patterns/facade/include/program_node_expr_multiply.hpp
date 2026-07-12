#ifndef __COMPILER_PROGRAM_NODE_EXPR_MULTIPLY_H__
#define __COMPILER_PROGRAM_NODE_EXPR_MULTIPLY_H__ 

#include "program_node.hpp"
#include "program_node_expr.hpp"
#include <memory>

class MultiplicationNode : public ExprNode
{
    public:
        typedef std::shared_ptr<MultiplicationNode> Ptr;
    public:
        MultiplicationNode(ProgNode::Ptr lhs, ProgNode::Ptr rhs);

    public:
        static Ptr create(ProgNode::Ptr lhs, ProgNode::Ptr rhs);

        ProgNode::Ptr lhs() const;
        ProgNode::Ptr rhs() const;

        virtual std::string to_string(std::string = "") const override;

    private:
        ProgNode::Ptr    _lhs;
        ProgNode::Ptr    _rhs;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_EXPR_MULTIPLY_H__ */
