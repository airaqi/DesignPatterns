#ifndef __COMPILER_PROGRAM_NODE_STMT_DO_H__
#define __COMPILER_PROGRAM_NODE_STMT_DO_H__ 

#include "program_node_expr.hpp"
#include "program_node_stmt.hpp"
#include <memory>
#include <ostream>

class DoNode : public StmtNode
{
    public:
        typedef std::shared_ptr<DoNode> Ptr;
    
        DoNode();

    public:
        static Ptr create();

        ExprNode::Ptr expr() const;
        void expr(const ExprNode::Ptr);

        StmtNode::Ptr stmt() const;
        void stmt(const StmtNode::Ptr);

        void init(StmtNode::Ptr, ExprNode::Ptr);
        void gen(int, int) override;

        virtual bool is_equals(const ProgNode &) const override;

        // virtual bool operator==(const ProgNode &) const override;
        // virtual bool operator!=(const ProgNode &) const override;

        virtual std::string print(std::string = "") const override;

        friend std::ostream& operator<<(std::ostream &, const DoNode &);
        friend std::ostream& operator<<(std::ostream &, const DoNode::Ptr);


    private:
        ExprNode::Ptr   _expr;
        StmtNode::Ptr   _stmt;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_STMT_DO_H__ */
