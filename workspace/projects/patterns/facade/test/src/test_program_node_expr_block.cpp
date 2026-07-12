#include "compiler_tag.hpp"
#include "doctest_main.h"
#include "program_node_builder.hpp"
#include "program_node_expr_block.hpp"
#include "program_node_expr_variable.hpp"
#include "program_node_expression.hpp"
#include <iostream>

TEST_CASE("BlockNode")
{
    BlockNode &block = *new BlockNode();
    
    CHECK(block.isBlock());
    CHECK(block.isExpression());
    CHECK_FALSE(block.isStatement());
    CHECK_FALSE(block.isValue());

    CHECK_EQ("[Block (0): \n]", block.to_string());
    CHECK_EQ(0, block.id());

    std::cout << "\'" << block.to_string() << "\'\n";

    VariableNode *var = new VariableNode( "test", Tag::STR);
    ExpressionNode *exp = new ExpressionNode();

    block.add(exp);
    exp->add(var);

    std::cout << block << "\n";

    delete &block;
}


