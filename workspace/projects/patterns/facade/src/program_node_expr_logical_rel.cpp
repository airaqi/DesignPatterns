#include "program_node_expr_logical_rel.hpp"
#include "compiler_token_word_type.hpp"
#include "compiler_token_word_type_array.hpp"
#include "program_node_expr_logical.hpp"
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

RelNode::RelNode(Token::Ptr token, ExprNode::Ptr l, ExprNode::Ptr r) :
    LogicalNode(token, l, r) {}

RelNode::Ptr RelNode::create(Token::Ptr token, ExprNode::Ptr l, ExprNode::Ptr r)
{
    RelNode::Ptr inst = RelNode::Ptr(new RelNode(token, l, r));
    inst->initialize();
    return inst;
}

Type::Ptr RelNode::check(Type::Ptr p1, Type::Ptr p2)
{
    std::cout << "RelNode::check(" << p1 << ", " << p2 << ")\n";

    std::cout << "RelNode::check()" 
        << " p1 cast: " << std::dynamic_pointer_cast<Array>(p1) 
        << " p2 cast: " << std::dynamic_pointer_cast<Array>(p2)
        << " p1 == p2: " << (p1 == p2)
        << std::endl;
    if ((std::dynamic_pointer_cast<Array>(p1)) != nullptr || (std::dynamic_pointer_cast<Array>(p2) != nullptr))
        return Type::Null;
    else if (*p1 == *p2)
        return Type::Bool;
    return Type::Null;
}

void RelNode::jumping(int t, int f) 
{
    ExprNode::Ptr a = lhs()->reduce();
    ExprNode::Ptr b = rhs()->reduce();

    std::string test = static_cast<std::ostringstream>(std::ostringstream()
            << a->to_string() << " "
            << op()->to_string() << " "
            << b->to_string()).str();
    emitjumps(test, t, f);
}
