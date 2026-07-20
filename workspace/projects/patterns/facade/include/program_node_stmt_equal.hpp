#ifndef __COMPILER_PROGRAM_NODE_STMT_EQUAL_H__
#define __COMPILER_PROGRAM_NODE_STMT_EQUAL_H__ 

#include "program_node.hpp"
#include "program_node_stmt.hpp"
#include <memory>
#include <string>

class EqualNode : public StmtNode
{
    public:
        typedef std::shared_ptr<EqualNode> Ptr;

    public:
        EqualNode(ProgNode::Ptr lhs, ProgNode::Ptr rhs);

    public:
        static Ptr create(ProgNode::Ptr lhs, ProgNode::Ptr rhs);

        ProgNode::Ptr lhs() const {  return _lhs; }
        ProgNode::Ptr rhs() const { return _rhs; }

       virtual bool is_equals(const ProgNode &) const override; 
        virtual std::string to_string(std::string prefix = "") const override;

    private:
        ProgNode::Ptr _lhs;
        ProgNode::Ptr _rhs;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_STMT_EQUAL_H__ */
