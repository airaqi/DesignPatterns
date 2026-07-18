#include "program_node_stmt_setelem.hpp"
#include "compiler_token_word_type_array.hpp"
#include "program_node_expr_op_access.hpp"
#include <format>
#include <memory>
#include <sstream>
#include <string>

SetElemNode::SetElemNode(AccessNode::Ptr x, ExprNode::Ptr y) : _array(x->array()), _index(x->index()), _expr(y) {}

SetElemNode::Ptr SetElemNode::create(AccessNode::Ptr x, ExprNode::Ptr y)
{
    return std::make_shared<SetElemNode>(x, y);
}

Type::Ptr SetElemNode::check(Type::Ptr p1, Type::Ptr p2)
{
    if (std::dynamic_pointer_cast<Array>(p1) != nullptr || std::dynamic_pointer_cast<Array>(p2) != nullptr)
        return nullptr;
    else if (p1 == p2)
        return p2;
    else if (Type::numeric(p1) && Type::numeric(p2))
        return p2;
    return nullptr;
}

void SetElemNode::gen(int b, int a)
{
    std::string s1 = _index->reduce()->to_string();
    std::string s2 = _expr->reduce()->to_string();
    emit(static_cast<std::ostringstream>(std::ostringstream() 
                << _array->to_string() << "[" << s1 << "]" << " = " << s2).str());
}

std::string SetElemNode::print(std::string prefix) const
{
    return std::format("{}[{}(id:{}, arr:{}, idx:{}, exp:{})]", prefix, "SetElem", id(), _array->print(), _index->print(), _expr->print());
}
