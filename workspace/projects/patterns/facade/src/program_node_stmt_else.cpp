#include "program_node_stmt_else.hpp"
#include <format>
#include <memory>
#include <ostream>
#include <sstream>
#include <string>

ElseNode::ElseNode(ExprNode::Ptr e, StmtNode::Ptr s1, StmtNode::Ptr s2) : 
    _expr(e),
    _stmt1(s1),
    _stmt2(s2) 
{
    if (expr()->type() != Type::Bool)
        expr()->error("Boolean required in if");
}

ElseNode::Ptr ElseNode::create(ExprNode::Ptr e, StmtNode::Ptr s1, StmtNode::Ptr s2) 
{
    return std::make_shared<ElseNode>(e, s1, s2);
}

void ElseNode::gen(int b, int a)
{
    int label1 = newlabel();
    int label2 = newlabel();
    expr()->jumping(0, label1);

    emitlabel(label1);
    stmt1()->gen(label1, a);
    emit(static_cast<std::ostringstream>(std::ostringstream() << "goto L" << a).str());

    emitlabel(label2);
    stmt2()->gen(label2, a);
}

bool ElseNode::is_equals(const ProgNode & that) const
{
    const ElseNode &th = static_cast<const ElseNode &>(that);
    return (expr() == th.expr() && stmt1() == th.stmt1() && stmt2() == th.stmt2()); 
}

bool ElseNode::operator==(const ProgNode & that) const { return is_equals(that); }
bool ElseNode::operator!=(const ProgNode & that) const { return !(*this == that); }

std::ostream& operator<<(std::ostream& out, const ElseNode & that) { out << that.to_string(); return out; }
std::ostream& operator<<(std::ostream& out, const ElseNode::Ptr that) { return operator<<(out, *that); }

std::string ElseNode::print(std::string prefix) const
{
    return std::format("{}[Else({}, {}, {}) : {}]", 
            prefix, _expr->print(), _stmt1->print(), _stmt2->print(), StmtNode::print());
}
