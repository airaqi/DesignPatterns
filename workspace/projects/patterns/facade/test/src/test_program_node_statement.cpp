#include "doctest_main.h"
#include "program_node_stmt.hpp"

TEST_CASE("StatementNode")
{
    SUBCASE("initialization")
    {
        StmtNode::Ptr node = StmtNode::create();
        CHECK(node->isStatement());
    }

}
