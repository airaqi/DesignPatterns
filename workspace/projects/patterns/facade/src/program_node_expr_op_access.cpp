#include "program_node_expr_op_access.hpp"
#include "program_node_expr_id.hpp"
#include "program_node_expr_op.hpp"
#include <format>
#include <memory>
#include <string>

AccessNode::AccessNode(Id::Ptr a, ExprNode::Ptr i, Type::Ptr p) : 
    OpNode(Word::idx, p), 
    _array(a), 
    _index(i) {}

AccessNode::Ptr AccessNode::create(Id::Ptr a, ExprNode::Ptr i, Type::Ptr p) 
{
    return std::make_shared<AccessNode>(a, i, p);
}

ExprNode::Ptr AccessNode::gen()
{
    ExprNode::Ptr i = _index->reduce();
    return AccessNode::create(_array, i, type());
}

void AccessNode::jumping(int t, int f) 
{
    emitjumps(this->reduce()->to_string(), t, f);
}

std::string AccessNode::to_string(std::string prefix) const
{
    return std::format("{}[ {} ]", _array->to_string(), _index->to_string());
}

std::string AccessNode::print(std::string prefix) const
{
    return std::format("{}[Access({}, {})]", prefix, array()->print(), index()->print());
}
