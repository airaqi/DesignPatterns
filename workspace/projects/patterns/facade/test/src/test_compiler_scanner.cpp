#include "compiler_scanner.hpp"
#include "compiler_tag.hpp"
#include "compiler_token.hpp"
#include "compiler_token_num.hpp"
#include "compiler_token_word.hpp"
#include "compiler_token_word_type.hpp"
#include "doctest_main.h"
#include <memory>
#include <sstream>
#include <string>

TEST_CASE("Scanner")
{
    SUBCASE("character")
    {
        std::string s = "a";
        std::stringstream ss(s);
        Scanner tin(ss);

        Token::Ptr actual = tin.scan();
        Word::Ptr expected = Word::create(s, Tag::ID);

        CHECK_EQ(*expected, *actual);
    }

    SUBCASE("string")
    {
        std::string s = "aaa";
        std::stringstream ss(s);
        Scanner tin(ss);
        Token::Ptr actual = tin.scan();
        Word::Ptr expected = Word::create(s, Tag::ID);

        CHECK_EQ(*expected, *actual);
    }
 
    SUBCASE("string with underscore")
    {
        std::string s = "aaa_123";
        std::stringstream ss(s);
        Scanner tin(ss);
        Word::Ptr expected = Word::create(s, Tag::ID);
        Token::Ptr actual = tin.scan();
        CHECK_EQ(*expected, *actual);
    }

    SUBCASE("numeric")
    {
        std::string s = "123";
        int n = std::stoi(s);
        std::stringstream ss(s);
        Scanner tin(ss);
        CHECK_EQ(*Num::create(n), *tin.scan());
    }

    SUBCASE("assignment")
    {
        std::string s1 = "aa", s2 = "=", s3 = "123", sp = " ", s = s1 + sp + s2 + sp + s3;
        
        int n = std::stoi(s3);
        std::stringstream ss(s);
        Scanner tin(ss);

        CHECK_EQ(*Word::create(s1, Tag::ID), *tin.scan());
        CHECK_EQ(*Word::asgn(), *tin.scan());
        CHECK_EQ(*Num::create(n), *tin.scan());
    }

    SUBCASE("Equality")
    {
        std::string sp = " ", s1 = "aa", s2 = "==", s3 = "123", s = s1 + sp + s2 + sp + s3;
        int n = std::stoi(s3);

        std::stringstream ss(s);
        Scanner tin(ss);

        CHECK_EQ(*Word::create(s1, Tag::ID), *tin.scan());
        CHECK_EQ(*Word::eq(), *tin.scan());
        CHECK_EQ(*Num::create(n), *tin.scan());
    }

    SUBCASE("eof")
    {
        std::string s = "aa";
        std::stringstream ss(s);
        Scanner tin(ss);
        
        CHECK_FALSE(tin.eof());
        Token::Ptr t = tin.scan();
        CHECK_EQ(*Word::create(s, Tag::ID), *t);
        CHECK(tin.eof());

        tin.putback(t);
        CHECK_FALSE(tin.eof());

        t = tin.scan();
        CHECK(tin.eof());
        
    }

    SUBCASE("push back")
    {
        std::stringstream ss("int a = 10;");
        Scanner tin(ss);
        auto t1 = tin.scan(),
              t2 = tin.scan();

        CHECK_EQ(*Type::Int(), *t1);
        CHECK_EQ(*Word::create("a", Tag::ID), *t2);

        tin.putback(t1);
        tin.putback(t2);

        CHECK_EQ(*Word::create("a", Tag::ID), *tin.scan());
        CHECK_EQ(*Type::Int(), *tin.scan());
        
    }

    SUBCASE("line and index and column")
    {
        std::stringstream ss("int a = 10;\na = 5;\n");
        Scanner tin(ss);

        auto t = tin.scan();
        CHECK_EQ(*Type::Int(), *t);
        CHECK_EQ(3, t->index());
        CHECK_EQ(3, t->column());
        CHECK_EQ(0, t->line());

        t = tin.scan();
        CHECK_EQ(*Word::create("a", Tag::ID), *t);
        CHECK_EQ(5, t->index());
        CHECK_EQ(5, t->column());
        CHECK_EQ(0, t->line());

        t = tin.scan();
        CHECK_EQ(*Word::asgn(), *t);
        CHECK_EQ(7, t->index());
        CHECK_EQ(7, t->column());
        CHECK_EQ(0, t->line());

        t = tin.scan();
        CHECK_EQ(*Num::create(10), *t);
        CHECK_EQ(10, t->index());
        CHECK_EQ(10, t->column());
        CHECK_EQ(0, t->line());

        t = tin.scan();
        CHECK_EQ(*Word::scln(), *t);
        CHECK_EQ(11, t->index());
        CHECK_EQ(11, t->column());
        CHECK_EQ(0, t->line());

        t = tin.scan();
        CHECK_EQ(*Word::create("a", Tag::ID), *t);
        CHECK_EQ(13, t->index());
        CHECK_EQ(1, t->column());
        CHECK_EQ(1, t->line());

        t = tin.scan();
        CHECK_EQ(*Word::asgn(), *t);
        CHECK_EQ(15, t->index());
        CHECK_EQ(3, t->column());
        CHECK_EQ(1, t->line());

        t = tin.scan();
        CHECK_EQ(*Num::create(5), *t);
        CHECK_EQ(17, t->index());
        CHECK_EQ(5, t->column());
        CHECK_EQ(1, t->line());

        t = tin.scan();
        CHECK_EQ(*Word::scln(), *t);
        CHECK_EQ(18, t->index());
        CHECK_EQ(6, t->column());
        CHECK_EQ(1, t->line());

    }

    SUBCASE("keywords")
    {
        const int sz = 13;
        std::string keywords[sz] = { 
            "int", "float", "bool", "char", 
            "&&", "||", "true", "false", 
            "if", "else", "while", "do", 
            "break" };
        Token::Ptr types[sz] = { 
            Type::Int(), Type::Float(), Type::Bool(), Type::Char(), 
            Word::And(), Word::Or(), Word::True(), Word::False(),
            Word::create("if", Tag::IF), 
            Word::create("else", Tag::ELSE), 
            Word::create("while", Tag::WHILE), 
            Word::create("do", Tag::DO),
            Word::create("break", Tag::BREAK)};

        for (int i = 0; i < sz; i++)
        {
            std::stringstream sin(keywords[i]);
            Scanner scanner(sin);
            Token::Ptr kwo = scanner.scan();
            CHECK_EQ(*types[i], *kwo);
        }

    }

    /*std::string s = "int a = 10;\nString test = \"Hi\";\nif(a == 1 && x != 79)\n{ \ttest = 0;\n\ty=5.4;\n\tname_1=\"Hello\";\n}";*/
    /*std::stringstream ss(s);*/
    /*Scanner tin(sym, ss);*/
    /*Token t = tin.scan();*/

    /*std::cout << s << "\n\n";*/

    /*std::cout << t << "\n";*/
    /*CHECK_EQ(sym.Tag::INT, t.tag());*/
    /*t = tin.scan();*/
    /*std::cout << t << "\n";*/
    /*CHECK_EQ(sym._NTERM, t.tag());*/

    /*t = tin.scan();*/
    /*std::cout << t << "\n";*/
    /*CHECK_EQ(Tag::ASSGN, t.tag());*/

    
}
