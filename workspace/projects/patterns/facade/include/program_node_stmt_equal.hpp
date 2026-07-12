#ifndef __COMPILER_PROGRAM_NODE_STMT_EQUAL_H__
#define __COMPILER_PROGRAM_NODE_STMT_EQUAL_H__ 

#include "program_node.hpp"
#include "program_node_stmt.hpp"
#include <memory>
#include <sstream>
#include <string>

class EqualNode : public StmtNode
{
    public:
        typedef std::shared_ptr<EqualNode> Ptr;

    public:
        EqualNode(ProgNode::Ptr lhs, ProgNode::Ptr rhs) : _lhs(lhs), _rhs(rhs) {}

    public:
        static Ptr create(ProgNode::Ptr lhs, ProgNode::Ptr rhs) { return Ptr(new EqualNode(lhs, rhs)); }

        ProgNode::Ptr lhs() const {  return _lhs; }
        ProgNode::Ptr rhs() const { return _rhs; }

        virtual std::string to_string(std::string prefix = "") const override 
        {
            std::stringstream sout;
            std::string subfix = prefix  + "  ";
            sout << prefix << "[Equal (" << std::to_string(id()) << "): \n" 
                << lhs()->to_string(subfix) << "\n"
                << rhs()->to_string(subfix) << "\n"
                << prefix << "]";
            return sout.str();
        }

    private:
        ProgNode::Ptr _lhs;
        ProgNode::Ptr _rhs;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_STMT_EQUAL_H__ */
