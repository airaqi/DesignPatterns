#ifndef __COMPILER_PROGRAM_NODE_EXPR_LOGICAL_NOT_H__
#define __COMPILER_PROGRAM_NODE_EXPR_LOGICAL_NOT_H__ 

#include "program_node_expr_logical.hpp"
#include <memory>
#include <string>
class NotNode : public LogicalNode
{
    public:
        typedef std::shared_ptr<NotNode> Ptr;

        //virtual ~NotNode() {}
        NotNode(Token::Ptr token, ExprNode::Ptr e);

    public:
        static Ptr create(Token::Ptr token, ExprNode::Ptr e);

        virtual void jumping(int t, int f) override;

        virtual std::string to_string(std::string prefix = "") const override;
        virtual std::string print(std::string = "") const override;

};

#endif /* ifndef __COMPILER_PROGRAM_NODE_EXPR_LOGICAL_NOT_H__ */
