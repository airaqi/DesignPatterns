#include "program_node_stmt_do.hpp"
#include "plog/Log.h"
#include <format>
#include <memory>
#include <ostream>
#include <string>

DoNode::DoNode() : _expr(nullptr), _stmt(nullptr) {}

DoNode::Ptr DoNode::create() 
{
    return std::make_shared<DoNode>();
}

ExprNode::Ptr DoNode::expr() const { return _expr; }
void DoNode::expr(const ExprNode::Ptr e) { _expr = e; }

StmtNode::Ptr DoNode::stmt() const { return _stmt; }
void DoNode::stmt(StmtNode::Ptr s) { _stmt = s; }

void DoNode::init(StmtNode::Ptr s, ExprNode::Ptr e) 
{
    PLOGD << "(" << s << ", " << e << ") e.type: " << e->type();

    _expr = e;
    _stmt = s;
    if (_expr->type() != Type::Bool())
        _expr->error("boolean required in do");
}
void DoNode::gen(int b, int a)
{
    after(a);
    int label = newlabel();
    _stmt->gen(b, label);
    emitlabel(label);
    _expr->jumping(b, 0);
}

bool DoNode::is_equals(const ProgNode & that) const
{
    const DoNode& th = static_cast<const DoNode &>(that);
    return (expr() == th.expr() && stmt() == th.stmt()) ;
}

/* bool DoNode::operator==(const ProgNode & that) const */
/* { */
/*     return is_equals(that); */
/* } */
/*  */
/* bool DoNode::operator!=(const ProgNode & that) const */
/* { */
/*     return !(*this == that); */
/* } */

std::string DoNode::print(std::string prefix) const
{
    return std::format("{}[Do({}, {}): {}]", prefix, _stmt->print(), _expr->print(), StmtNode::print());
}

std::ostream& operator<<(std::ostream& out, const DoNode & that) { out << that.to_string(); return out; }
std::ostream& operator<<(std::ostream& out, const DoNode::Ptr that) { return operator<<(out, *that); }
