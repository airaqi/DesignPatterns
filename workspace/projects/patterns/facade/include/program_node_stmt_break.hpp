#ifndef __COMPILER_PROGRAM_NODE_STMT_BREAK_H__
#define __COMPILER_PROGRAM_NODE_STMT_BREAK_H__ 

#include "program_node_stmt.hpp"
#include <format>
#include <memory>

class BreakNode : public StmtNode
{
    public:
        typedef std::shared_ptr<BreakNode> Ptr;

    public:
        BreakNode() 
        {
            if (_stmt->Enclosing == StmtNode::Null)
                error("unenclosed break");
            _stmt = std::dynamic_pointer_cast<StmtNode>(StmtNode::Enclosing);
        }

    public:
        static Ptr create() { return std::make_shared<BreakNode>(); }

        void gen(int b, int a) override
        {
            emit(std::format("{}{}", "goto L", _stmt->after()));
        }

        StmtNode::Ptr stmt() const { return _stmt; }

        virtual bool is_equals(const ProgNode & other) const override { return stmt() == static_cast<const BreakNode&>(other).stmt(); }

    private:
        StmtNode::Ptr   _stmt;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_STMT_BREAK_H__ */
