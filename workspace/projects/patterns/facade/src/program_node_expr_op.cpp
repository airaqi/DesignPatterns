#include "program_node_expr_op.hpp"
#include "program_node_expr.hpp"
#include "program_node_expr_temp.hpp"
#include <format>
#include <iostream>
#include <string>

OpNode::OpNode(Token::Ptr token, Type::Ptr t) : ExprNode(token, t) {}

OpNode::Ptr OpNode::create(Token::Ptr token, Type::Ptr t) 
{
    return OpNode::Ptr(new OpNode(token, t));
}

ExprNode::Ptr OpNode::reduce() 
{
    std::cout << "OpNode::reduce() in" 
        //<< " this: " << *this 
        << std::endl;

    ExprNode::Ptr x = gen();
    TempNode::Ptr t = TempNode::create(_type);
    emit(std::format("{} = {}", t->to_string(), x->to_string()));
    std::cout << "ObNode::reduce() x: " << x << " t: " << t << std::endl;
    return t;
}

std::string OpNode::print(std::string prefix) const
{
    return std::format("{}[Op : {}]", prefix, ExprNode::print(prefix));
}
