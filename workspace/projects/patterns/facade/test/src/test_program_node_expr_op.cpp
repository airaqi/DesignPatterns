#include "doctest_main.h"
#include "program_node_expr_op.hpp"

TEST_CASE("OpNode Test")
{
    SUBCASE("initialization")
    {
        OpNode::Ptr node = OpNode::create(nullptr, nullptr);
        CHECK(node->isExpression());
    }
}
