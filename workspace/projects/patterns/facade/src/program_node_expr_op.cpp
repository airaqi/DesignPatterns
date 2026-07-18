#include "program_node_expr_op.hpp"
#include "plog/Log.h"
#include "program_node_expr.hpp"
#include "program_node_expr_temp.hpp"
#include <format>
#include <memory>
#include <string>

OpNode::OpNode(Token::Ptr token, Type::Ptr t) : ExprNode(token, t) {}

OpNode::Ptr OpNode::create(Token::Ptr token, Type::Ptr t) 
{
    return std::make_shared<OpNode>(token, t);
}

ExprNode::Ptr OpNode::reduce() 
{
    PLOGD << "() in";

    ExprNode::Ptr x = gen();
    TempNode::Ptr t = TempNode::create(_type);
    emit(std::format("{} = {}", t->to_string(), x->to_string()));
    PLOGD << " - x: " << x << " t: " << t;
    return t;
}

std::string OpNode::print(std::string prefix) const
{
    return std::format("{}[Op : {}]", prefix, ExprNode::print(prefix));
}
