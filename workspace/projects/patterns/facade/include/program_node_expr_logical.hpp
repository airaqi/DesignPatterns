#ifndef __COMPILER_PROGRAM_NODE_EXPR_LOCICAL_H__
#define __COMPILER_PROGRAM_NODE_EXPR_LOCICAL_H__ 

#include "program_node_expr.hpp"
#include <memory>
#include <string>

class LogicalNode : public ExprNode 
{
    public:
        typedef std::shared_ptr<LogicalNode> Ptr;
    
    private:
        ExprNode::Ptr _lhs;
        ExprNode::Ptr _rhs;

    public:
        LogicalNode(Token::Ptr, ExprNode::Ptr, ExprNode::Ptr);

    public:
        static Ptr create(Token::Ptr, ExprNode::Ptr, ExprNode::Ptr);
        void initialize();

        void lhs(ExprNode::Ptr l);     ExprNode::Ptr lhs() const;
        void rhs(ExprNode::Ptr r);     ExprNode::Ptr rhs() const;

        virtual Type::Ptr check(Type::Ptr, Type::Ptr);
        virtual ExprNode::Ptr gen() override;

        virtual std::string to_string(std::string = "") const override;
        virtual std::string print(std::string = "") const override;

};
#endif /* ifndef __COMPILER_PROGRAM_NODE_EXPR_LOCICAL_H__ */
