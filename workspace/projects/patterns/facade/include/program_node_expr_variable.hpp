#ifndef __COMPILER_PROGRAM_NODE_EXPR_VAR_H__
#define __COMPILER_PROGRAM_NODE_EXPR_VAR_H__ 

#include "program_node_expr.hpp"
#include <memory>
#include <string>

class VariableNode : public ExprNode
{
    public:
        typedef std::shared_ptr<VariableNode> Ptr;

    public:
        VariableNode(std::string name, Type::Ptr t);

    public:
        static Ptr create(std::string name, Type::Ptr);

        virtual ~VariableNode();

        std::string name() const;     void name(std::string n);

        virtual bool isVariable() override;

        virtual void traverse(CodeGenerator &) override;

        virtual std::string to_string(std::string = "") const override;

    private:
        std::string         _name;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_EXPR_VAR_H__ */
