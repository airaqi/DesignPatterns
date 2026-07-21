#include "compiler_parser.hpp"
#include "compiler_scanner.hpp"
#include "doctest_main.h"
#include "plog/Log.h"
#include "program_node_builder.hpp"
#include "program_node_expr_const.hpp"
#include "program_node_stmt.hpp"
#include "program_node_stmt_do.hpp"
#include "program_node_stmt_seq.hpp"
#include "program_node_stmt_set.hpp"
#include "program_node_stmt_while.hpp"
#include <iomanip>
#include <ios>
#include <iostream>
#include <sstream>

int indent = 10;

TEST_CASE("Parser")
{

    SUBCASE("block") 
    {
      std::stringstream ss("{}");
      Scanner scanner(ss);
      ProgramNodeBuilder builder;
      Parser parser(scanner, builder);
      StmtNode::Ptr expected = parser.parse();

      StmtNode::Ptr actual = StmtNode::Null;

      CHECK(expected->isStatement());
      CHECK_EQ(*actual, *expected);
      CHECK_EQ(expected->out().str(), actual->out().str());

      PLOGD << std::left << std::setw(indent) << "code" << ": " << ss.str();
      PLOGD << std::left << std::setw(indent) << "expected" << ": " << expected->print();
      PLOGD << std::left << std::setw(indent) << "actual" << ": " << actual->print();
      PLOGD << std::left << std::setw(indent) << "exp out" << ": " << expected->out().str();
      PLOGD << std::left << std::setw(indent) << "act out" << ": " << actual->out().str();

    }

    SUBCASE("int variable")
    {
        std::stringstream ss("{int x;}");
        Scanner scanner(ss);
        ProgramNodeBuilder builder;
        Parser parser(scanner, builder);
        StmtNode::Ptr actual = parser.parse();

        StmtNode::Ptr expected = StmtNode::Null;

        CHECK(actual->isStatement());
        CHECK_EQ(*expected, *actual);
        CHECK_EQ(expected->out().str(), actual->out().str());
        
        PLOGD << std::left << std::setw(indent) << "code" << ": " << ss.str();
        PLOGD << std::left << std::setw(indent) << "expected" << ": " << expected->print();
        PLOGD << std::left << std::setw(indent) << "actual" << ": " << actual->print();
        PLOGD << std::left << std::setw(indent) << "exp out" << ": " << expected->out().str();
        PLOGD << std::left << std::setw(indent) << "act out" << ": " << actual->out().str();
    }

    SUBCASE("float variable")
    {
        std::stringstream sin("{float f;}");
        Scanner scanner(sin);
        ProgramNodeBuilder builder;
        Parser parser(scanner, builder);
        StmtNode::Ptr actual = parser.parse();

        StmtNode::Ptr expected = StmtNode::Null;

        CHECK(actual->isStatement());
        CHECK_EQ(*expected, *actual);
        CHECK_EQ(expected->out().str(), actual->out().str());
 
        PLOGD << std::left << std::setw(indent) << "code" << ": " << sin.str();
        PLOGD << std::left << std::setw(indent) << "expected" << ": " << expected->print();
        PLOGD << std::left << std::setw(indent) << "actual" << ": " << actual->print();
        PLOGD << std::left << std::setw(indent) << "exp out" << ": " << expected->out().str();
        PLOGD << std::left << std::setw(indent) << "act out" << ": " << actual->out().str();
     }

    SUBCASE("int array")
    {
        std::stringstream sin("{int[100] a;}");
        Scanner scanner(sin);
        ProgramNodeBuilder builder;
        Parser parser(scanner, builder);
        StmtNode::Ptr actual = parser.parse();

        StmtNode::Ptr expected = StmtNode::Null;

        CHECK(actual->isStatement());
        CHECK_EQ(*expected, *actual);
        CHECK_EQ(expected->out().str(), actual->out().str());
 
        PLOGD << std::left << std::setw(indent) << "code" << ": " << sin.str();
        PLOGD << std::left << std::setw(indent) << "expected" << ": " << expected->print();
        PLOGD << std::left << std::setw(indent) << "actual" << ": " << actual->print();
        PLOGD << std::left << std::setw(indent) << "exp out" << ": " << expected->out().str();
        PLOGD << std::left << std::setw(indent) << "act out" << ": " << actual->out().str();
    }

    SUBCASE("bool true")
    {
      std::stringstream sin("{ bool b; b = true; }");
      Scanner scanner(sin);
      ProgramNodeBuilder builder;
      Parser parser(scanner, builder);

      StmtNode::Ptr actual = parser.parse();
      SeqNode::Ptr seqNode = SeqNode::create(
          SetNode::create(
            Id::create(
              Word::create("b", Tag::ID), 
              Type::Bool, 
              0), 
            ConstNode::True), 
          StmtNode::Null);
      StmtNode::Ptr expected = seqNode;
       
      CHECK(actual->isStatement());
      CHECK_EQ(*expected, *actual);
      CHECK_EQ(expected->out().str(), actual->out().str());

      PLOGD << std::left << std::setw(indent) << "code" << ": " << sin.str();
      PLOGD << std::left << std::setw(indent) << "expected" << ": " << expected->print();
      PLOGD << std::left << std::setw(indent) << "actual" << ": " << actual->print();
      PLOGD << std::left << std::setw(indent) << "exp out" << ": " << expected->out().str();
      PLOGD << std::left << std::setw(indent) << "act out" << ": " << actual->out().str();
    
    }

    SUBCASE("while")
    {
        std::stringstream sin("{ while(true) {} }");
        Scanner scanner(sin);
        ProgramNodeBuilder builder;
        Parser parser(scanner, builder);

        StmtNode::Ptr actual = parser.parse();

        WhileNode::Ptr whilenode = WhileNode::create();
        ConstNode::Ptr trueConst = ConstNode::create(Word::True, Type::Bool);
        whilenode->init(ConstNode::True, StmtNode::Null);
        SeqNode::Ptr seq = SeqNode::create(whilenode, StmtNode::Null);
        StmtNode::Ptr expected = seq;

        CHECK(actual->isStatement());
        CHECK_EQ(*expected, *actual);
        CHECK_EQ(expected->out().str(), actual->out().str());
        
        PLOGD << std::left << std::setw(indent) << "code" << ": " << sin.str();
        PLOGD << std::left << std::setw(25) << "actual: " << ":" << actual->print();
        PLOGD << std::left << std::setw(25) << "expected: " << ":" << seq->print();
        PLOGD << std::left << std::setw(indent) << "exp out" << ": " << expected->out().str();
        PLOGD << std::left << std::setw(indent) << "act out" << ": " << actual->out().str();
    }

    SUBCASE("do while")
    {
        std::stringstream sin("{ do; while(true); }");
        Scanner scanner(sin);
        ProgramNodeBuilder builder;
        Parser parser(scanner, builder);
        StmtNode::Ptr actual = parser.parse();

        DoNode::Ptr doNode = DoNode::create();
        doNode->init(StmtNode::Null, ConstNode::True);
        SeqNode::Ptr seq = SeqNode::create(doNode, StmtNode::Null);
        StmtNode::Ptr expected = seq;

        CHECK(actual->isStatement());
        CHECK_EQ(*expected, *actual);
        CHECK_EQ(expected->out().str(), actual->out().str());

        PLOGD << std::left << std::setw(indent) << "code" << ": " << sin.str();
        PLOGD << std::left << std::setw(indent) << "expected" << ": " << seq->print();
        PLOGD << std::left << std::setw(indent) << "actual" << ": " << actual->print();
        PLOGD << std::left << std::setw(indent) << "exp out" << ": " << expected->out().str();
        PLOGD << std::left << std::setw(indent) << "act out" << ": " << actual->out().str();
 
    }

    SUBCASE("if")
    {
        std::stringstream sin("{ if(true) {} }");
        Scanner scanner(sin);
        ProgramNodeBuilder builder;
        Parser parser(scanner, builder);
        StmtNode::Ptr actual = parser.parse();

        IfNode::Ptr ifNode = IfNode::create(ConstNode::True, StmtNode::Null);
        auto seq = SeqNode::create(ifNode, StmtNode::Null);
        StmtNode::Ptr expected = seq;

        CHECK(actual->isStatement());
        CHECK_EQ(*expected, *actual);
        CHECK_EQ(expected->out().str(), actual->out().str());

        PLOGD << std::left << std::setw(indent) << "code" << ": " << sin.str();
        PLOGD << std::left << std::setw(indent) << "expected" << ": " << seq->print();
        PLOGD << std::left << std::setw(indent) << "actual" << ": " << actual->print();
        PLOGD << std::left << std::setw(indent) << "exp out" << ": " << expected->out().str();
        PLOGD << std::left << std::setw(indent) << "act out" << ": " << actual->out().str();
    }
}
