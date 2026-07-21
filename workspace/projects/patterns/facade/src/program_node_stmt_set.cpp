#include "program_node_stmt_set.hpp"
#include "plog/Log.h"
#include "program_node_expr.hpp"
#include <format>
#include <memory>
#include <ostream>
#include <sstream>

SetNode::SetNode(Id::Ptr id, ExprNode::Ptr e) : _id(id), _expr(e) 
{
    if (check(_id->type(), _expr->type()) == nullptr)
        error("type error");
}

SetNode::Ptr SetNode::create(Id::Ptr id, ExprNode::Ptr e) 
{
    return std::make_shared<SetNode>(id, e);
}

Id::Ptr SetNode::tid() const { return _id; }
void SetNode::tid(const Id::Ptr i) { _id = i; }

ExprNode::Ptr SetNode::expr() const { return _expr; }
void SetNode::expr(const ExprNode::Ptr e) { _expr = e; }

Type::Ptr SetNode::check(Type::Ptr p1, Type::Ptr p2)
{
    if (Type::numeric(p1) && Type::numeric(p2))
        return p2;
    else if (p1 == Type::Bool && p2 == Type::Bool)
        return p2;
    return Type::Null;
}

void SetNode::gen(int b, int a)
{
    PLOGD << "id: " << tid()->print() << ", expr: " << expr()->print(); 
    emit(static_cast<std::ostringstream>(std::ostringstream() 
                << tid()->to_string() << " = "
                << expr()->gen()->to_string()).str());
}

bool SetNode::is_equals(const ProgNode & that) const 
{
    PLOGD << " >> " << print() << " == " << that.print();

    if (typeid(*this) != typeid(that)) return false;
    const SetNode & th = static_cast<const SetNode &>(that);
    return (tid()->equals(th.tid()) && expr()->equals(th.expr()));
}

std::string SetNode::print(std::string prefix) const
{
    return std::format("{}[Set({}, {}, {})]", prefix, id(), tid()->print(), _expr->print());
}

// bool SetNode::operator==(const ProgNode & that) const { return is_equals(that); }
// bool SetNode::operator!=(const ProgNode & that) const { return !(*this == that); }

std::ostream& operator<<(std::ostream& out, const SetNode & that) { out << that.to_string(); return out; }
std::ostream& operator<<(std::ostream& out, const SetNode::Ptr that) { return operator<<(out, *that); }
