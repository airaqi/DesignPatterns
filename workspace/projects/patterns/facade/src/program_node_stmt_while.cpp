#include "program_node_stmt_while.hpp"
#include <format>
#include <ostream>
#include <string>

WhileNode::WhileNode() : _expr(nullptr), _stmt(nullptr) {}

WhileNode::Ptr WhileNode::create()
{
    return WhileNode::Ptr(new WhileNode());
}

ExprNode::Ptr WhileNode::expr() const { return _expr; }
void WhileNode::expr(const ExprNode::Ptr e) { _expr = e; }

StmtNode::Ptr WhileNode::stmt() const { return _stmt; }
void WhileNode::stmt(const StmtNode::Ptr s) { _stmt = s; }

void WhileNode::init(ExprNode::Ptr e, StmtNode::Ptr s)
{
    _expr = e;
    _stmt = s;
    if (_expr->type() != Type::Bool)
        _expr->error("booleam required in while");
}

void WhileNode::gen(int b, int a)
{
    after(a);
    _expr->jumping(0, a);
    int label = newlabel();
    emitlabel(label);
    _stmt->gen(label, b);
    emit(std::format("{}{}", "goto L", b));
}

bool WhileNode::equals(const ProgNode & that) const 
{
    const WhileNode & th = static_cast<const WhileNode &>(that);
    return (expr() == th.expr() && stmt() == th.stmt());
}

std::string WhileNode::print(std::string prefix) const
{
    return std::format("{}[While({},{},{})]", prefix, id(), _expr->print(), _stmt->print());
}

bool WhileNode::operator==(const ProgNode & that) const { return equals(that); }
bool WhileNode::operator!=(const ProgNode & that) const { return !(*this == that); }

std::ostream& operator<<(std::ostream& out, const WhileNode & that) { out << that.to_string(); return out; }
std::ostream& operator<<(std::ostream& out, const WhileNode::Ptr that) { return operator<<(out, *that); }
