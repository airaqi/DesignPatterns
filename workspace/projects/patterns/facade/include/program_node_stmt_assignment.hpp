#ifndef __COMPILER_PROGRAM_NODE_STMT_ASSIGNMENT_H__
#define __COMPILER_PROGRAM_NODE_STMT_ASSIGNMENT_H__ 

#include "program_node_stmt.hpp"
#include <memory>
#include <string>

class AssignmentNode : public StmtNode
{
    public:
        typedef std::shared_ptr<AssignmentNode> Ptr;

    public:
        AssignmentNode(ProgNode::Ptr var, ProgNode::Ptr expr);

    public:
        static Ptr create(ProgNode::Ptr, ProgNode::Ptr);

        virtual void variable(ProgNode::Ptr);
        virtual ProgNode::Ptr variable() const;
        virtual void expression(ProgNode::Ptr);
        virtual ProgNode::Ptr expression() const;

        virtual void scope(ProgNode::Ptr) override;
        virtual void traverse(CodeGenerator &) override;

        virtual std::string to_string(std::string = "") const override;
        virtual std::string print(std::string = "") const override;

    private:
        ProgNode::Ptr _variable;
        ProgNode::Ptr _expression;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_STMT_ASSIGNMENT_H__ */
