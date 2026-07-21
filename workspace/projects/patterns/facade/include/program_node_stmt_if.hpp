#ifndef __COMPILER_PROGRAM_NODE_STMT_CONSITION_H__
#define __COMPILER_PROGRAM_NODE_STMT_CONSITION_H__ 

#include "program_node.hpp"
#include "program_node_expr.hpp"
#include "program_node_stmt.hpp"
#include <memory>
#include <ostream>

class IfNode : public StmtNode
{
    public:
        typedef std::shared_ptr<IfNode> Ptr;

    public:
        IfNode(ExprNode::Ptr, StmtNode::Ptr);

    public:
        static Ptr create(ExprNode::Ptr, StmtNode::Ptr);

        ExprNode::Ptr expr() const;
        StmtNode::Ptr stmt() const;

        virtual void gen(int b, int a) override;

        virtual void scope(ProgNode::Ptr) override;

        virtual void traverse(CodeGenerator &) override;

        virtual bool is_equals(const ProgNode &) const override;
        virtual std::string print(std::string = "") const override;

        // virtual bool operator==(const ProgNode &) const override;
        // virtual bool operator!=(const ProgNode &) const override;

        friend std::ostream& operator<<(std::ostream &, const IfNode &);
        friend std::ostream& operator<<(std::ostream &, const IfNode::Ptr);

    private:
        ExprNode::Ptr         _expr;
        StmtNode::Ptr         _stmt;
};
#endif /* ifndef __COMPILER_PROGRAM_NODE_STMT_CONSITION_H__ */
