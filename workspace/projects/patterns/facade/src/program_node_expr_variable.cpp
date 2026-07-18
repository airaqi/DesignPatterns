#include "program_node_expr_variable.hpp"
#include <memory>
#include <sstream>
#include <string>

VariableNode::VariableNode(std::string n, Type::Ptr t) : ExprNode(nullptr, t), _name(n) {}
VariableNode::~VariableNode() {}

VariableNode::Ptr VariableNode::create(std::string name, Type::Ptr t) {
    return std::make_shared<VariableNode>(name, t);
}

void VariableNode::name(std::string n) { _name = n; }
std::string VariableNode::name() const { return _name; }

bool VariableNode::isVariable() { return true; }

void VariableNode::traverse(CodeGenerator& gen)
{
    gen.visit(this);
}

std::string VariableNode::to_string(std::string prefix) const
{
    std::stringstream sout;
    sout << prefix
        << "[Variable (" << id() << ") :" 
        << " name: " << name() 
        << " type: " << type() 
        << "]";

    return sout.str();
}


