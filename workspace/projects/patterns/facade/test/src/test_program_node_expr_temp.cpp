#include "doctest_main.h"
#include "plog/Log.h"
#include "program_node_expr_temp.hpp"

TEST_CASE("TempNode")
{
  SUBCASE("Creation")
  {
    TempNode::Ptr node = TempNode::create(Type::Int);
    CHECK(node->isExpression());
    CHECK_FALSE(node->isStatement());
  }

  SUBCASE("to_string")
  {
    TempNode::Ptr node = TempNode::create(Type::Int);
    CHECK_EQ("t2", node->to_string());

    PLOGD << node->to_string();
  }
}
