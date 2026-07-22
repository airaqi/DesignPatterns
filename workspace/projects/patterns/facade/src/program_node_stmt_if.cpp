#include "program_node_stmt_if.hpp"
#include "program_node.hpp"
#include <memory>
#include <ostream>
#include <sstream>
#include <string>


IfNode::IfNode(ExprNode::Ptr e, StmtNode::Ptr s) : _expr(e), _stmt(s) 
{
    if (expr()->type() != Type::Bool())
        expr()->error("boolean required in if");
}

IfNode::Ptr IfNode::create(ExprNode::Ptr e, StmtNode::Ptr s) 
{
    return std::make_shared<IfNode>(e, s);
}

ExprNode::Ptr IfNode::expr() const
{
    return _expr;
}

StmtNode::Ptr IfNode::stmt() const
{
    return _stmt;
}

void IfNode::scope(ProgNode::Ptr parent)
{
    ProgNode::scope(parent);

    _expr->scope(ProgNode::scope());
    _stmt->scope(ProgNode::scope());
}

void IfNode::traverse(CodeGenerator& generator)
{
    generator.visit(this);
}

void IfNode::gen(int b, int a)
{
    int label = newlabel();
    expr()->jumping(0, a);
    emitlabel(label);
    stmt()->gen(label, a);
}

bool IfNode::is_equals(const ProgNode & that) const 
{
    const IfNode & th = static_cast<const IfNode &>(that);
    return (expr() == th.expr() && stmt() == th.stmt());
}

std::string IfNode::print(std::string prefix) const
{
    std::stringstream sout;
    std::string subfix = prefix + "  ";
    sout << prefix << "[If (" << id() << "): " 
        << expr()->print()  << "?"
        << stmt()->to_string() << "]";
    return sout.str();
}

// bool IfNode::operator==(const ProgNode & that) const { return is_equals(that); }
// bool IfNode::operator!=(const ProgNode & that) const { return !(*this == that); }

std::ostream& operator<<(std::ostream& out, const IfNode & that) { out << that.to_string(); return out; }
std::ostream& operator<<(std::ostream& out, const IfNode::Ptr that) { return operator<<(out, *that); }


