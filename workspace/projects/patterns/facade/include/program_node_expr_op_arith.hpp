#ifndef __COMPILER_PROGRAM_NODE_EXPR_OP_ARITH_H__
#define __COMPILER_PROGRAM_NODE_EXPR_OP_ARITH_H__ 

#include "compiler_token.hpp"
#include "program_node_expr_op.hpp"
#include "program_node_expr.hpp"
#include <memory>

class ArithNode : public OpNode
{
    public: 
        typedef std::shared_ptr<ArithNode> Ptr;
    public:
        ArithNode(Token::Ptr, ExprNode::Ptr, ExprNode::Ptr);
    public:
        static Ptr create(Token::Ptr, ExprNode::Ptr, ExprNode::Ptr);

        virtual ExprNode::Ptr gen() override;

        virtual std::string to_string(std::string prefix = "") const override;
        virtual std::string print(std::string = "") const override;

        void lhs(ExprNode::Ptr l) { _lhs = l; }        ExprNode::Ptr lhs() const { return _lhs; }
        void rhs(ExprNode::Ptr r) { _rhs = r; }        ExprNode::Ptr rhs() const { return _rhs; }

    private:
        ExprNode::Ptr _lhs;
        ExprNode::Ptr _rhs;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_EXPR_OP_ARITH_H__ */
