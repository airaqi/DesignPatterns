#include "compiler_parser.hpp"
#include "compiler_scanner.hpp"
#include "doctest_main.h"
#include "program_node_builder.hpp"
#include "program_node_expr_const.hpp"
#include "program_node_stmt_seq.hpp"
#include "program_node_stmt_while.hpp"
#include <iostream>
#include <sstream>

TEST_CASE("Parser")
{
    SUBCASE("int variable")
    {
        std::stringstream ss("{int x;}");
        Scanner scanner(ss);
        ProgramNodeBuilder builder;
        Parser parser(scanner, builder);

        StmtNode::Ptr sout = parser.parse();
        std::cout << ">>>>> Parser::int variable test " << sout->print() << std::endl;
        CHECK(sout->isStatement());
    }

    SUBCASE("float variable")
    {
        std::stringstream sin("{float f;}");
        Scanner scanner(sin);
        ProgramNodeBuilder builder;
        Parser parser(scanner, builder);
        StmtNode::Ptr sout = parser.parse();
        std::cout << ">>>>> Parser::int variable test " << sout->print() << std::endl;

        CHECK(sout->isStatement());
    }

    SUBCASE("int array")
    {
        std::stringstream sin("{int[100] a;}");
        Scanner scanner(sin);
        ProgramNodeBuilder builder;
        Parser parser(scanner, builder);

        StmtNode::Ptr sout = parser.parse();
        std::cout << ">>>>> Parser::int variable test " << sout->print() << std::endl;
        CHECK(sout->isStatement());
    }

    SUBCASE("while")
    {
        std::stringstream sin("{ while(true) {} }");
        Scanner scanner(sin);
        ProgramNodeBuilder builder;
        Parser parser(scanner, builder);

        StmtNode::Ptr sout = parser.parse();
        std::cout << ">>>>> Parser::while test " << sout->print() << std::endl;
        WhileNode::Ptr whilenode = WhileNode::create();
        ConstNode::Ptr trueConst = ConstNode::create(Word::True, Type::Bool);
        whilenode->init(trueConst, StmtNode::Null);
        SeqNode::Ptr seq = SeqNode::create(whilenode, StmtNode::Null);
        std::cout << ">>>>> Ref while " << seq->print() << std::endl;
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
        std::cout << ">>>>> Parser::do while test " << sout->print() << std::endl;
        CHECK(sout->isStatement());

    }
}
