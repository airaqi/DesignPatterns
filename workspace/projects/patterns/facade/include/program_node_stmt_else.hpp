#ifndef __COMPILER_PROGRAM_NODE_STMT_ELSE_H__
#define __COMPILER_PROGRAM_NODE_STMT_ELSE_H__ 

#include "program_node_expr.hpp"
#include "program_node_stmt.hpp"
#include <memory>
#include <ostream>

class ElseNode : public StmtNode
{
    public:
        typedef std::shared_ptr<ElseNode> Ptr;

        ElseNode(ExprNode::Ptr, StmtNode::Ptr, StmtNode::Ptr);

    public:
        static Ptr create(ExprNode::Ptr, StmtNode::Ptr, StmtNode::Ptr);

        void expr(ExprNode::Ptr e) { _expr = e; }       ExprNode::Ptr expr() const  { return _expr; }
        void stmt1(StmtNode::Ptr s) { _stmt1 = s; }     StmtNode::Ptr stmt1() const { return _stmt1; }
        void stmt2(StmtNode::Ptr s) { _stmt2 = s; }     StmtNode::Ptr stmt2() const { return _stmt2; }

        virtual void gen(int b, int a) override;

        virtual bool is_equals(const ProgNode &) const override;

        virtual std::string print(std::string = "") const override;

        // virtual bool operator==(const ProgNode &) const override;
        // virtual bool operator!=(const ProgNode &) const override;

        friend std::ostream& operator<<(std::ostream &, const ElseNode &);
        friend std::ostream& operator<<(std::ostream &, const ElseNode::Ptr &);

    private:
        ExprNode::Ptr       _expr;
        StmtNode::Ptr       _stmt1;
        StmtNode::Ptr       _stmt2;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_STMT_ELSE_H__ */
