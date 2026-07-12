#include "program_node_stmt.hpp"
#include "compiler_code_generator.hpp"
#include "program_node.hpp"
#include <format>
#include <ostream>
#include <stdexcept>

const StmtNode::Ptr StmtNode::Null = StmtNode::create();
StmtNode::Ptr StmtNode::Enclosing = StmtNode::create();

StmtNode::StmtNode() : _after(0) {}

StmtNode::Ptr StmtNode::create()
{
    return StmtNode::Ptr(new StmtNode());
}

void StmtNode::traverse(CodeGenerator& generator)
{
    generator.visit(this);
}

bool StmtNode::isStatement()
{
    return true;
}


std::string StmtNode::to_string(std::string prefix) const
{
    return std::format("{}[Stmt({}, {})]", prefix, id(), _after);
}

std::string StmtNode::print(std::string prefix) const
{
    return std::format("{}[Stmt({}, {}){}]", 
            prefix, id(), _after, 
            (*this == *StmtNode::Null) ? ": Null" : "");
}

void StmtNode::add(ProgNode::Ptr) {}
void StmtNode::remove(ProgNode::Ptr) {}
const ProgNode& StmtNode::child(const int) const { throw std::runtime_error("Illegal child inquiry."); }
void StmtNode::getSourcePosition(int &l, int &i) {}
 

bool StmtNode::equals(const ProgNode &other) const
{
    return false;
}

std::ostream& operator<<(std::ostream& out, const StmtNode& that) { out << that.to_string(); return out; }
std::ostream& operator<<(std::ostream& out, const StmtNode::Ptr that) { return operator<<(out, *that.get()); }
