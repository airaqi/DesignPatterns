#include "compiler_tag.hpp"
#include "compiler_token.hpp"
#include "compiler_token_num.hpp"
#include "compiler_token_real.hpp"
#include "compiler_token_word.hpp"
#include "compiler_token_word_type.hpp"
#include "compiler_token_word_type_array.hpp"
#include "doctest_main.h"
#include "plog/Log.h"
#include <memory>

TEST_CASE("Token")
{
    SUBCASE("initialization")
    {
        Token t(Tag::AND);
        CHECK_EQ(Tag::AND, t.tag());
        CHECK_EQ(0, t.line());
        CHECK_EQ(0, t.index());
        CHECK_EQ("[Token(AND)]", t.print());
        CHECK_EQ("AND", t.to_string());
    }

    SUBCASE("Word")
    {
        Word::Ptr word = Word::create("Hello", Tag::ID);
        CHECK_EQ("Hello", word->value());
        CHECK_EQ(0, word->line());
        CHECK_EQ(0, word->index());
        CHECK_EQ(Tag::ID, word->tag());
        CHECK_EQ("Hello", word->to_string());
        CHECK_EQ("[Word(Hello): [Token(ID)]]", word->print());
        CHECK_EQ(*Word::create("Hello", Tag::ID), *word);
        CHECK(Word::create("Hello", Tag::ID)->equals(word));

        PLOGD << word;
    }

    SUBCASE("Num")
    {
        Num::Ptr num = Num::create(10);
        CHECK_EQ(10, num->value());
        CHECK_EQ(Tag::NUM, num->tag());
        CHECK_EQ(0, num->line());
        CHECK_EQ(0, num->index());
        CHECK_EQ(*Num::create(10), *num);
        CHECK_EQ("10", num->to_string());
        CHECK_EQ("[Num(10): [Token(NUM)]]", num->print());
        PLOGD << num;
    }

    SUBCASE("Real")
    {
        std::shared_ptr<Real> real = Real::create(1.5);
        CHECK_EQ(1.5, real->value());
        CHECK_EQ(Tag::REAL, real->tag());
        CHECK_EQ(0, real->line());
        CHECK_EQ(0, real->index());
        CHECK_EQ(*Real::create(1.5), *real);
        CHECK_EQ("1.5", real->to_string());
        CHECK_EQ("[Real(1.5): [Token(REAL)]]", real->print());
        PLOGD << *real;
    }

    SUBCASE("Type")
    {
        CHECK_EQ(Tag::BASIC, Type::Int->tag());
        CHECK_EQ(Tag::BASIC, Type::Float->tag());
        CHECK_EQ(Tag::BASIC, Type::Char->tag());

        CHECK_EQ("int", Type::Int->value());
        CHECK_EQ("float", Type::Float->value());
        CHECK_EQ("char", Type::Char->value());

        CHECK_EQ(true, Type::numeric(Type::Int));
        CHECK_EQ(true, Type::numeric(Type::Float));
        CHECK_EQ(true, Type::numeric(Type::Char));
        CHECK_EQ(false, Type::numeric(Type::Bool));

        CHECK_EQ(Type::Int, Type::max(Type::Int, Type::Int));
        CHECK_EQ(Type::Float, Type::max(Type::Int, Type::Float));
        CHECK_EQ(Type::Null, Type::max(Type::Bool, Type::Bool));
        CHECK_EQ(Type::Int, Type::max(Type::Int, Type::Char));
        CHECK_EQ(Type::Char, Type::max(Type::Char, Type::Char));
        
        PLOGD << Type::Int->to_string();
    }

    SUBCASE("Array")
    {
        auto array = Array::create(10, Type::Int),
                array2 = Array::create(20, Type::Int);
        CHECK_EQ(Type::Int, array->of());
        CHECK_EQ(10, array->size());
        CHECK_NE(array, array2);

        PLOGD << array->to_string();
    }
}


