#include "program_node_expr_temp.hpp"
#include "compiler_token_word_type.hpp"
#include "program_node_expr.hpp"
#include <format>
#include <memory>
#include <string>

TempNode::TempNode(Type::Ptr p) : ExprNode(Word::temp, p), _number(++_count) {}

TempNode::Ptr TempNode::create(Type::Ptr p) 
{ 
    return std::make_shared<TempNode>(p); 
}

std::string TempNode::to_string(std::string prefix)
{
    return std::format("t{}", _number);
}
