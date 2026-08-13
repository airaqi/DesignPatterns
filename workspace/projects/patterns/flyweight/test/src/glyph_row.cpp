#include "glyph_row.hpp"
#include "doctest_main.h"
#include "glyph_character.hpp"
#include "glyph_context.hpp"
#include "glyph_factory.hpp"

TEST_CASE("GlyphRow")
{
    GlyphFactory factory = GlyphFactory::get();
    Font::Ptr times12 = factory.getFont("Times New Roman", 12),
              times9red = factory.getFont("Times New Roman", 9, Font::Color::Value::RED);

    GlyphContext ctxt(times12);

    SUBCASE("init")
    {
        GlyphRow::Ptr r1 = factory.getRow(),
                      r2 = factory.getRow();

        CHECK_EQ(true, typeid(r1.get()) == typeid(r2.get()));
    }

    SUBCASE("insert")
    {
        GlyphRow::Ptr r1 = factory.getRow();
        GlyphCharacter::Ptr cha = factory.getCharacter('a');

        r1->insert(cha, ctxt);

        CHECK_EQ(true, r1->get(0).equal(*cha));
    }

    SUBCASE("Equality")
    {
        GlyphRow::Ptr r1 = factory.getRow(),
                      r2 = factory.getRow();
        GlyphCharacter::Ptr cha = factory.getCharacter('a');

        CHECK_EQ(true, *r1 == *r2);

        r1->insert(cha, ctxt);
        CHECK_EQ(false, *r1 == *r2);

        INFO("r1: " << r1->to_string());
        INFO("r2: " << r2->to_string());
    }

    SUBCASE("to_string")
    {
        GlyphRow::Ptr r1 = factory.getRow(),
                      r2 = factory.getRow();
        GlyphCharacter::Ptr cha = factory.getCharacter('a');

        r1->insert(cha, ctxt);

        INFO("r1: " << r1->to_string());
        INFO("r2: " << r2->to_string());

        CHECK_EQ("\n[Row: a]", r1->to_string());
        CHECK_EQ("\n[Row: ]", r2->to_string());
    }
}
