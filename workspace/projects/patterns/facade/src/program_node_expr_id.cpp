#include "program_node_expr_id.hpp"
#include "compiler_token_word_type.hpp"
#include "plog/Log.h"
#include "program_node_expr.hpp"
#include <format>
#include <iostream>
#include <memory>
#include <ostream>

Id::Id(Word::Ptr id, Type::Ptr p, int b) : ExprNode(id, p), _offset(b) {}

Id::Ptr Id::create(Word::Ptr id, Type::Ptr p, int b) { return std::make_shared<Id>(id, p, b); }

int Id::offset() const { return _offset; }
void Id::offset(int o) { _offset = o; }

std::string Id::to_string(std::string prefix) const
{
    return ExprNode::to_string();
}

std::string Id::print(std::string prefix) const
{
    std::string attribs = std::format("id:{}, op:{}, typ:{}", id(), op()->to_string(), type()->to_string());
    return std::format("{}[Id(off:{}, {})]", prefix, _offset, attribs);
}

bool Id::is_equals(const ProgNode& that) const
{
    PLOGD << print() << " = " << that.print();

    const Id& id = dynamic_cast<const Id&>(that);
    return ExprNode::is_equals(that) && (_offset == id.offset());
}

// bool operator==(const Id& lhs, const Id& rhs)           { return lhs.is_equals(rhs); }
// bool operator==(const Id::Ptr lhs, const Id::Ptr rhs)   { return *lhs.get() == *rhs.get(); }

// bool operator!=(const Id& lhs, const Id& rhs)           { return !(lhs == rhs); }
// bool operator!=(const Id::Ptr lhs, const Id::Ptr rhs)   { return !(lhs == rhs); }

std::ostream& operator<<(std::ostream& out, const Id& that)
{
    out << that.to_string();
    return out;
}

std::ostream& operator<<(std::ostream& out, Id::Ptr that) { return operator<<(out, *that.get()); }
