#ifndef __COMPILER_PROGRAM_NODE_EXPR_OP_H__
#define __COMPILER_PROGRAM_NODE_EXPR_OP_H__ 

#include "compiler_token.hpp"
#include "compiler_token_word_type.hpp"
#include "program_node_expr.hpp"
#include <memory>

class OpNode : public ExprNode
{
    public:
        typedef std::shared_ptr<OpNode> Ptr;
    public:
        OpNode(Token::Ptr token, Type::Ptr type);

    public:
        static Ptr create(Token::Ptr token, Type::Ptr type);

        virtual ExprNode::Ptr reduce() override;

        virtual std::string print(std::string = "") const override;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_EXPR_OP_H__ */
