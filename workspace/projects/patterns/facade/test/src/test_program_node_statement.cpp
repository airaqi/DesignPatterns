#include "doctest_main.h"
#include "plog/Log.h"
#include "program_node_expr_const.hpp"
#include "program_node_stmt.hpp"
#include "program_node_stmt_seq.hpp"
#include "program_node_stmt_while.hpp"

TEST_CASE("StatementNode")
{
    SUBCASE("initialization")
    {
        StmtNode::Ptr node = StmtNode::create();
        CHECK(node->isStatement());
    }

    SUBCASE("While Sequence Equality")
    {
      WhileNode::Ptr whileNode = WhileNode::create();
      whileNode->init(ConstNode::True(), StmtNode::Null());
      SeqNode::Ptr seq1 = SeqNode::create(whileNode, StmtNode::Null());

      WhileNode::Ptr whileNode2 = WhileNode::create();
      whileNode2->init(ConstNode::True(), StmtNode::Null());
      SeqNode::Ptr seq2 = SeqNode::create(whileNode2, StmtNode::Null());

      CHECK_EQ(*whileNode, *whileNode2);
      CHECK_EQ(*seq1, *seq2);

      PLOGD << seq1;
      PLOGD << seq2;
    }

    SUBCASE("Null Equality") 
    {
      CHECK_EQ(*StmtNode::Null(), *StmtNode::Null());
    }

    SUBCASE("Boolean Equality") 
    {
      CHECK_EQ(ConstNode::True(), ConstNode::True());
      CHECK_EQ(ConstNode::False(), ConstNode::False());
      CHECK_NE(ConstNode::True(), ConstNode::False());

    }

    SUBCASE("While Equality")
    {
      WhileNode::Ptr whileNode1 = WhileNode::create();
      whileNode1->init(ConstNode::True(), StmtNode::Null());

      WhileNode::Ptr whileNode2 = WhileNode::create();
      whileNode2->init(ConstNode::True(), StmtNode::Null());

      CHECK_EQ(*whileNode1, *whileNode2);

    }

    SUBCASE("Sequence Equality")
    {
      SeqNode::Ptr nseq1 = SeqNode::create(StmtNode::Null(), StmtNode::Null());
      SeqNode::Ptr nseq2 = SeqNode::create(StmtNode::Null(), StmtNode::Null());

      CHECK_EQ(*nseq1, *nseq2);

      PLOGD << nseq1;
      PLOGD << nseq2;
    }

}
