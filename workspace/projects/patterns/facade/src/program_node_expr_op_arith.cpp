#include "program_node_expr_op_arith.hpp"
#include "plog/Log.h"
#include "program_node_expr.hpp"
#include <format>
#include <memory>
#include <string>

ArithNode::ArithNode(Token::Ptr token, ExprNode::Ptr lhs, ExprNode::Ptr rhs) :
    OpNode(token, Type::Null()),
    _lhs(lhs),
    _rhs(rhs) 
{
        type(Type::max(lhs->type(), rhs->type()));
        if (type() == Type::Null()) error(std::format("type error: {} type cannot be null", this->print()));
}

ArithNode::Ptr ArithNode::create(Token::Ptr token, ExprNode::Ptr lhs, ExprNode::Ptr rhs) 
{
    return std::make_shared<ArithNode>(token, lhs, rhs);
}

ExprNode::Ptr ArithNode::gen()
{
    PLOGV << "() lhs: " << lhs()->print() << " rhs: " << rhs()->print();

    ExprNode::Ptr keep_lhs_alive = _lhs;
    ExprNode::Ptr keep_rhs_alive = _rhs;

    Token::Ptr o = op();
    ExprNode::Ptr l = keep_lhs_alive->reduce();
    ExprNode::Ptr r = keep_rhs_alive->reduce();
    return ArithNode::create(o, l, r);
}

std::string ArithNode::to_string(std::string prefix) const
{
    return std::format("{}{} {} {}", prefix, lhs()->to_string(), op()->to_string(), rhs()->to_string());
}

std::string ArithNode::print(std::string prefix) const
{
    return std::format("{}[Arith({}, {}, {})]", prefix, lhs()->print(), op()->print(), rhs()->print());
}
