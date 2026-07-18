#include "compiler_parser.hpp"
#include "compiler_scanner.hpp"
#include "doctest_main.h"
#include "plog/Log.h"
#include "program_node_builder.hpp"
#include "program_node_expr_const.hpp"
#include "program_node_stmt.hpp"
#include "program_node_stmt_seq.hpp"
#include "program_node_stmt_while.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

TEST_CASE("Parser")
{

    SUBCASE("block") 
    {
      std::stringstream ss("{}");
      Scanner scanner(ss);
      ProgramNodeBuilder builder;
      Parser parser(scanner, builder);

      StmtNode::Ptr sout = parser.parse();
      PLOGD << sout->print();
      /* StmtNode::Ptr block = StmtNode::create(); */
      /* CHECK(sout->isBlock()); */
      /* CHECK_EQ(*block, *sout); */
    }

    SUBCASE("int variable")
    {
        std::stringstream ss("{int x;}");
        Scanner scanner(ss);
        ProgramNodeBuilder builder;
        Parser parser(scanner, builder);

        StmtNode::Ptr sout = parser.parse();
        PLOGD << ">>>>> Parser::int variable test " << sout->print();
        CHECK(sout->isStatement());
    }

    SUBCASE("float variable")
    {
        std::stringstream sin("{float f;}");
        Scanner scanner(sin);
        ProgramNodeBuilder builder;
        Parser parser(scanner, builder);
        StmtNode::Ptr sout = parser.parse();
        PLOGD << ">>>>> Parser::float variable test " << sout->print();

        CHECK(sout->isStatement());
    }

    SUBCASE("int array")
    {
        std::stringstream sin("{int[100] a;}");
        Scanner scanner(sin);
        ProgramNodeBuilder builder;
        Parser parser(scanner, builder);

        StmtNode::Ptr sout = parser.parse();
        PLOGD << ">>>>> Parser::int array variable test " << sout->print();
        CHECK(sout->isStatement());
    }

    SUBCASE("bool true")
    {
      std::stringstream sin("{ bool b; b = true; }");
      Scanner scanner(sin);
      ProgramNodeBuilder builder;
      Parser parser(scanner, builder);

      ConstNode::Ptr trueConst = ConstNode::True;
      StmtNode::Ptr sout = parser.parse();
      PLOGD << ">>>>> Parser::boolean true constant " << sout->print();
      CHECK(sout->isStatement());
    }

    SUBCASE("while")
    {
        std::stringstream sin("{ while(true) {} }");
        Scanner scanner(sin);
        ProgramNodeBuilder builder;
        Parser parser(scanner, builder);

        StmtNode::Ptr sout = parser.parse();
        PLOGD << std::left << std::setw(25) << ">>>>> Parser::while test" << ":" << sout->print();

        WhileNode::Ptr whilenode = WhileNode::create();
        ConstNode::Ptr trueConst = ConstNode::create(Word::True, Type::Bool);
        whilenode->init(trueConst, StmtNode::Null);
        SeqNode::Ptr seq = SeqNode::create(whilenode, StmtNode::Null);
        PLOGD << std::left << std::setw(25) << ">>>>> Ref while " << ":" << seq->print();
        CHECK(sout->isStatement());
        CHECK_EQ(*seq, *sout);

    }

    SUBCASE("do while")
    {
        std::stringstream sin("{ do; while(true); }");
        Scanner scanner(sin);
        ProgramNodeBuilder builder;
        Parser parser(scanner, builder);
        StmtNode::Ptr sout = parser.parse();
        PLOGD << ">>>>> Parser::do while test " << sout->print();
        CHECK(sout->isStatement());

    }
}
