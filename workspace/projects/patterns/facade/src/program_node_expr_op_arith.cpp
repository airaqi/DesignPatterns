#include "program_node_expr_op_arith.hpp"
#include "program_node_expr.hpp"
#include <format>
#include <string>

ArithNode::ArithNode(Token::Ptr token, ExprNode::Ptr lhs, ExprNode::Ptr rhs) :
    OpNode(token, Type::Null),
    _lhs(lhs),
    _rhs(rhs) 
{
        type(Type::max(lhs->type(), rhs->type()));
        if (type() == Type::Null) error(std::format("type error: {} type cannot be null", this->print()));
}

ArithNode::Ptr ArithNode::create(Token::Ptr token, ExprNode::Ptr lhs, ExprNode::Ptr rhs) 
{
    return ArithNode::Ptr(new ArithNode(token, lhs, rhs));
}

ExprNode::Ptr ArithNode::gen()
{
    //std::cout << "ArithNode::gen() lhs: " << lhs()->print() << " rhs: " << rhs()->print() << std::endl;
    Token::Ptr o = op();
    ExprNode::Ptr l = lhs()->reduce();
    ExprNode::Ptr r = rhs()->reduce();
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
