#include "program_node_expr_addition.hpp"
#include "plog/Log.h"
#include "program_node.hpp"
#include <memory>
#include <sstream>


AdditionNode::AdditionNode(ProgNode::Ptr lhs, ProgNode::Ptr rhs) : 
    ExprNode(nullptr, nullptr), _lhs(lhs), _rhs(rhs) {}

AdditionNode::Ptr AdditionNode::create(ProgNode::Ptr lhs, ProgNode::Ptr rhs) 
{
  return std::make_shared<AdditionNode>(lhs, rhs);
}

ProgNode::Ptr AdditionNode::lhs() const
{
    return _lhs;
}

ProgNode::Ptr AdditionNode::rhs() const
{
    return _rhs;
}

void AdditionNode::scope(ProgNode::Ptr parent)
{
    ExprNode::scope(parent);

    _rhs->scope(ProgNode::scope());
    _lhs->scope(ProgNode::scope());
}

std::string AdditionNode::to_string(std::string prefix) const
{
    std::stringstream sout;
    std::string subfix = prefix + "  ";
    PLOGD << lhs() << "\n" << rhs() << "\n";
    sout << prefix << "[Addition(" << id() << "): \n" 
        << lhs()->to_string(subfix) << "\n"
        << subfix << "+\n" 
        << rhs()->to_string(subfix) << "\n"
        << prefix << "]";
    return sout.str();
}
