#include "program_node_expr_const.hpp"
#include "compiler_token_num.hpp"
#include "compiler_token_word_type.hpp"
#include "plog/Log.h"
#include <format>
#include <memory>
#include <sstream>

ConstNode::Ptr ConstNode::True = ConstNode::create(Word::True, Type::Bool);
ConstNode::Ptr ConstNode::False = ConstNode::create(Word::False, Type::Bool);

ConstNode::ConstNode(Token::Ptr token, Type::Ptr type) : ExprNode(token, type) {}
ConstNode::ConstNode(int i) : ExprNode(Num::create(i), Type::Int) {}

ConstNode::Ptr ConstNode::create(Token::Ptr token, Type::Ptr type) 
{
    return std::make_shared<ConstNode>(token, type);
}

ConstNode::Ptr ConstNode::create(int i)
{
    return std::make_shared<ConstNode>(i);
}

void ConstNode::jumping(int t, int f)
{
    if (this == True.get() && t != 0)
        emit(static_cast<std::ostringstream>(std::ostringstream() << "goto L" << f).str());
    else if (this == False.get() && f != 0)
        emit(static_cast<std::ostringstream>(std::ostringstream() << "goto L" << f).str());
}

bool ConstNode::is_equals(const ProgNode & that) const 
{
    PLOGD << print() << " == " << that.print();
    if (typeid(that) != typeid(*this)) return false;
    const auto & other = static_cast<const ConstNode &>(that);
    return is_equals(other);
}

std::string ConstNode::print(std::string prefix) const
{
    std::string attribs = std::format("id:{}, op:{}, typ:{}", id(), op()->to_string(), type()->to_string());
    return std::format("{}[Const({})]", prefix, attribs);
}
