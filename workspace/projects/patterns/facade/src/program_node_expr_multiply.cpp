#include "program_node_expr_multiply.hpp"
#include <iostream>
#include <sstream>


MultiplicationNode::MultiplicationNode(ProgNode::Ptr lhs, ProgNode::Ptr rhs) : ExprNode(nullptr, nullptr), _lhs(lhs), _rhs(rhs) {}

ProgNode::Ptr MultiplicationNode::lhs() const
{
    return _lhs;
}


ProgNode::Ptr MultiplicationNode::rhs() const
{
    return _rhs;
}


std::string MultiplicationNode::to_string(std::string prefix) const
{
    std::stringstream sout;
    std::string subfix = prefix + "  ";
    std::cout << *lhs() << "\n" << *rhs() << "\n";
    sout << prefix << "[Multiply(" << id() << "): \n" 
        << lhs()->to_string(subfix) << "\n"
        << rhs()->to_string(subfix) << "]";
    return sout.str();
}
