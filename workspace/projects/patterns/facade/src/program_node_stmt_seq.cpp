#include "program_node_stmt_seq.hpp"
#include "program_node.hpp"
#include <format>
#include <memory>
#include <ostream>
#include <string>

SeqNode::SeqNode(StmtNode::Ptr s1, StmtNode::Ptr s2) : _stmt1(s1), _stmt2(s2) {}

SeqNode::Ptr SeqNode::create(StmtNode::Ptr s1, StmtNode::Ptr s2) 
{ 
    return std::make_shared<SeqNode>(s1, s2); 
}

StmtNode::Ptr SeqNode::stmt1() const { return _stmt1; }
void SeqNode::stmt1(const StmtNode::Ptr s) { _stmt1 = s; }

StmtNode::Ptr SeqNode::stmt2() const { return _stmt2; }
void SeqNode::stmt2(const StmtNode::Ptr s) { _stmt2 = s; }

void SeqNode::gen(int b, int a)
{
    if (_stmt1 == StmtNode::Null)
        _stmt2->gen(b, a);
    else if (_stmt2 == StmtNode::Null)
        _stmt1->gen(b, a);
    else 
    {
        int label = newlabel();
        _stmt1->gen(b, label);
        emitlabel(label);
        _stmt2->gen(label, a);
    }
}

bool SeqNode::equals(const ProgNode & that) const 
{
    const SeqNode& th = static_cast<const SeqNode &>(that);
    return (stmt1() == th.stmt1() && stmt2() == th.stmt2());
}

std::string SeqNode::to_string(std::string prefix) const
{
    return std::format("{}[Seq({}, {}, {})]", prefix, id(), _stmt1->print(), _stmt2->print());
}

std::string SeqNode::print(std::string prefix) const
{
    return std::format("{}\n[Seq({}, {}, {}\n)]", prefix, id(), _stmt1->print(), _stmt2->print());
}

bool SeqNode::operator==(const ProgNode & that) const { return equals(that); }
bool SeqNode::operator!=(const ProgNode & that) const { return !(*this == that); }

std::ostream& operator<<(std::ostream& out, const SeqNode & that) { out << that.to_string(); return out; }
std::ostream& operator<<(std::ostream& out, const SeqNode::Ptr that) { return operator<<(out, *that); }
