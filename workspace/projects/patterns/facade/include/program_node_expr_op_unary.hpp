#ifndef __COMPILER_PROGRAM_NODE_EXPR_OP_UNARY_H__
#define __COMPILER_PROGRAM_NODE_EXPR_OP_UNARY_H__ 

#include "program_node_expr_op.hpp"
#include <memory>
#include <string>

class UnaryNode : public OpNode
{
    public:
        typedef std::shared_ptr<UnaryNode> Ptr;

    private:
        ExprNode::Ptr _expr;

    protected:
        UnaryNode(Token::Ptr, ExprNode::Ptr);

    public:
        static Ptr create(Token::Ptr, ExprNode::Ptr);

        void expr(ExprNode::Ptr e);
        ExprNode::Ptr expr() const;

        virtual ExprNode::Ptr gen() override;
        virtual std::string to_string(std::string = "") const override;
        virtual std::string print(std::string = "") const override;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_EXPR_OP_UNARY_H__ */

