#ifndef __COMPILER_PROGRAM_NODE_STMT_SET_H__
#define __COMPILER_PROGRAM_NODE_STMT_SET_H__ 

#include "compiler_token_word_type.hpp"
#include "program_node_expr_id.hpp"
#include "program_node_expr.hpp"
#include "program_node_stmt.hpp"
#include <memory>
#include <ostream>
class SetNode : public StmtNode
{
    public:
        typedef std::shared_ptr<SetNode> Ptr;

        SetNode(Id::Ptr, ExprNode::Ptr);

    public:
        static Ptr create(Id::Ptr, ExprNode::Ptr);

        Id::Ptr tid() const;
        void tid(const Id::Ptr);

        ExprNode::Ptr expr() const;
        void expr(const ExprNode::Ptr);

        Type::Ptr check(Type::Ptr, Type::Ptr);
        virtual void gen(int, int) override;

        virtual bool is_equals(const ProgNode &) const override;
        virtual std::string print(std::string = "") const override;

        // virtual bool operator==(const ProgNode &) const override;
        // virtual bool operator!=(const ProgNode &) const override;

        friend std::ostream& operator<<(std::ostream &, const SetNode &);
        friend std::ostream& operator<<(std::ostream &, const SetNode::Ptr);

private:
        Id::Ptr         _id;
        ExprNode::Ptr   _expr;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_STMT_SET_H__ */
