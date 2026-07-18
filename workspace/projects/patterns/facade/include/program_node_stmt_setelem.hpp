#ifndef _COMPILER_PROGRAM_NODE_STMT_SETELEM_H__
#define _COMPILER_PROGRAM_NODE_STMT_SETELEM_H__ 

#include "program_node_expr_op_access.hpp"
#include "program_node_expr.hpp"
#include "program_node_stmt.hpp"
#include <memory>

class SetElemNode : public StmtNode
{
    public:
        typedef std::shared_ptr<SetElemNode> Ptr;

    public:
        SetElemNode(AccessNode::Ptr, ExprNode::Ptr);

    public:
        static Ptr create(AccessNode::Ptr, ExprNode::Ptr);

        Type::Ptr check(Type::Ptr, Type::Ptr);
        void gen(int, int);

        virtual std::string print(std::string = "") const override;

    private:
        Id::Ptr         _array;
        ExprNode::Ptr   _index;
        ExprNode::Ptr   _expr;
};

#endif /* ifndef _COMPILER_PROGRAM_NODE_STMT_SETELEM_H__ */
