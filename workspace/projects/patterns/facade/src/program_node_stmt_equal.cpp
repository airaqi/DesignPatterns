#include "program_node_stmt_equal.hpp"
#include <memory>
#include <sstream>

EqualNode::EqualNode(ProgNode::Ptr lhs, ProgNode::Ptr rhs) : _lhs(lhs), _rhs(rhs) {}

EqualNode::Ptr EqualNode::create(ProgNode::Ptr lhs, ProgNode::Ptr rhs) 
{
    return std::make_shared<EqualNode>(lhs, rhs);
  
}

bool EqualNode::equals(const ProgNode &) const {
  return false;
}

std::string EqualNode::to_string(std::string prefix) const 
{
    std::stringstream sout;
    std::string subfix = prefix  + "  ";
    sout << prefix << "[Equal (" << std::to_string(id()) << "): \n" 
        << lhs()->to_string(subfix) << "\n"
        << rhs()->to_string(subfix) << "\n"
        << prefix << "]";
    return sout.str();
}

