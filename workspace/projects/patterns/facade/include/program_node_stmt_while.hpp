#ifndef __COMPILER_PROGRAM_NODE_STMT_WHILE_H__
#define __COMPILER_PROGRAM_NODE_STMT_WHILE_H__ 

#include "program_node_expr.hpp"
#include "program_node_stmt.hpp"
#include <memory>
#include <ostream>
#include <string>

class WhileNode : public StmtNode
{
    public:
        typedef std::shared_ptr<WhileNode> Ptr;

        WhileNode();

        Ptr ptr() const;

    public:
        static Ptr create();

        ExprNode::Ptr expr() const;
        void expr(const ExprNode::Ptr);

        StmtNode::Ptr stmt() const;
        void stmt(const StmtNode::Ptr);

        void init(ExprNode::Ptr, StmtNode::Ptr);
        virtual void gen(int b, int a) override;

        virtual bool is_equals(const ProgNode &) const override;
        virtual std::string print(std::string = "") const override;

        virtual bool operator==(const ProgNode &) const override;
        virtual bool operator!=(const ProgNode &) const override;

        friend std::ostream& operator<<(std::ostream &, const WhileNode &);
        friend std::ostream& operator<<(std::ostream &, const WhileNode::Ptr);

    private:
        ExprNode::Ptr   _expr;
        StmtNode::Ptr   _stmt;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_STMT_WHILE_H__ */
