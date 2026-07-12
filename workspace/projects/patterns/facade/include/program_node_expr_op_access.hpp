#ifndef __COMPILER_PROGRAM_NODE_EXPR_OP_ACCESS_H__
#define __COMPILER_PROGRAM_NODE_EXPR_OP_ACCESS_H__ 

#include "compiler_token_word_type.hpp"
#include "program_node_expr_id.hpp"
#include "program_node_expr_op.hpp"
#include "program_node_expr.hpp"
#include <memory>
#include <string>

class AccessNode : public OpNode
{
    public:
        typedef std::shared_ptr<AccessNode> Ptr;

    private:
        Id::Ptr         _array;
        ExprNode::Ptr   _index;

    protected:
        AccessNode(Id::Ptr, ExprNode::Ptr, Type::Ptr);

    public:
        static Ptr create(Id::Ptr, ExprNode::Ptr, Type::Ptr);

        Id::Ptr array() const { return _array; }
        ExprNode::Ptr index() const { return _index; }

        virtual ExprNode::Ptr gen() override;
        virtual void jumping(int, int) override;
        
        virtual std::string to_string(std::string = "") const override;
        virtual std::string print(std::string = "") const override;

};

#endif /* ifndef __COMPILER_PROGRAM_NODE_EXPR_OP_ACCESS_H__ */
