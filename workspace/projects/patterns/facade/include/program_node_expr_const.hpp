#ifndef __COMPILER_PROGRAM_NODE_EXPR_CONST_H__
#define __COMPILER_PROGRAM_NODE_EXPR_CONST_H__ 

#include "program_node_expr.hpp"
#include <memory>

class ConstNode : public ExprNode 
{
    public:
        typedef std::shared_ptr<ConstNode> Ptr;

        static Ptr True, False;

        ConstNode(Token::Ptr, Type::Ptr);
        ConstNode(int i);

    public:
        static Ptr create(Token::Ptr, Type::Ptr);
        static Ptr create(int);

        virtual void jumping(int, int) override;

        virtual std::string print(std::string = "") const override;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_EXPR_CONST_H__ */
