#ifndef __COMPILER_PROGRAM_NODE_STMT_BREAK_H__
#define __COMPILER_PROGRAM_NODE_STMT_BREAK_H__ 

#include "program_node_stmt.hpp"
#include <memory>

class BreakNode : public StmtNode
{
    public:
        typedef std::shared_ptr<BreakNode> Ptr;

    public:
        BreakNode();

    public:
        static Ptr create();

        StmtNode::Ptr stmt() const;

        void gen(int b, int a) override;
        virtual bool is_equals(const ProgNode & other) const override;

    private:
        StmtNode::Ptr   _stmt;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_STMT_BREAK_H__ */
