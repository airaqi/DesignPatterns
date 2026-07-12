#include "program_node_expr_id.hpp"
#include "compiler_token_word_type.hpp"
#include "program_node_expr.hpp"
#include <format>
#include <iostream>
#include <ostream>

Id::Id(Word::Ptr id, Type::Ptr p, int b) : ExprNode(id, p), _offset(b) {}

Id::Ptr Id::create(Word::Ptr id, Type::Ptr p, int b) { return Id::Ptr(new Id(id, p, b)); }

int Id::offset() const { return _offset; }
void Id::offset(int o) { _offset = o; }

std::string Id::to_string(std::string prefix) const
{
    return ExprNode::to_string();
}

std::string Id::print(std::string prefix) const
{
    return std::format("{}[Id({}): {}]", prefix, _offset, ExprNode::print());
}

bool Id::equals(const ProgNode& that) const
{
    const Id& id = dynamic_cast<const Id&>(that);
    return ExprNode::equals(that) && (_offset == id.offset());
}

bool operator==(const Id& lhs, const Id& rhs)           { return lhs.equals(rhs); }
bool operator==(const Id::Ptr lhs, const Id::Ptr rhs)   { return *lhs.get() == *rhs.get(); }

bool operator!=(const Id& lhs, const Id& rhs)           { return !(lhs == rhs); }
bool operator!=(const Id::Ptr lhs, const Id::Ptr rhs)   { return !(lhs == rhs); }

std::ostream& operator<<(std::ostream& out, const Id& that)
{
    out << that.to_string();
    return out;
}

std::ostream& operator<<(std::ostream& out, Id::Ptr that) { return operator<<(out, *that.get()); }
