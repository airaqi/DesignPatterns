#include "program_node_stmt_assignment.hpp"
#include "program_node.hpp"
#include <format>
#include <sstream>
#include <string>


AssignmentNode::AssignmentNode(ProgNode::Ptr var, ProgNode::Ptr expr) : _variable(var), _expression(expr) {}

ProgNode::Ptr AssignmentNode::variable() const
{
    return _variable;
}


void AssignmentNode::variable(ProgNode::Ptr var)
{
    _variable = var;
}

ProgNode::Ptr AssignmentNode::expression() const
{
    return _expression;
}

void AssignmentNode::expression(ProgNode::Ptr expr)
{
    _expression = expr;
}


void AssignmentNode::scope(ProgNode::Ptr parent)
{
    ProgNode::scope(parent);

    _variable->scope(ProgNode::scope());
    _expression->scope(ProgNode::scope());
}


void AssignmentNode::traverse(CodeGenerator& generator)
{
    generator.visit(this);
}

std::string AssignmentNode::to_string(std::string prefix) const
{
    std::stringstream sout;
    std::string subfix = prefix + "  ";
    sout << prefix << "[Assign(" << id() << "): " 
        << _variable->to_string() << " = \n" 
        << _expression->to_string(subfix) << "\n" 
        << prefix << "]";
    return sout.str();
}

std::string AssignmentNode::print(std::string prefix) const
{
    return std::format("{}[Assign({}, {}, {})]", prefix, id(), variable()->print(), expression()->print());
}
