#ifndef __COMPILER_PROGRAM_NODE_STMT_BREAK_H__
#define __COMPILER_PROGRAM_NODE_STMT_BREAK_H__ 

#include "program_node_stmt.hpp"
#include <format>
#include <memory>

class BreakNode : public StmtNode
{
    public:
        typedef std::shared_ptr<BreakNode> Ptr;

    protected:
        BreakNode() 
        {
            if (_stmt->Enclosing == StmtNode::Null)
                error("unenclosed break");
            _stmt = std::dynamic_pointer_cast<StmtNode>(StmtNode::Enclosing);
        }

    public:
        static Ptr create() { return Ptr(new BreakNode()); }

        void gen(int b, int a)
        {
            emit(std::format("{}{}", "goto L", _stmt->after()));
        }

    private:
        StmtNode::Ptr   _stmt;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_STMT_BREAK_H__ */
