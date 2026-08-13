#include "glyph_column.hpp"
#include "doctest_main.h"
#include "font.hpp"
#include "glyph_character.hpp"
#include "glyph_context.hpp"
#include "glyph_factory.hpp"

TEST_CASE("GlyphColumn")
{
    GlyphFactory factory = GlyphFactory::get();
    Font::Ptr times12 = factory.getFont("Times New Roman", 12),
              times9red = factory.getFont("Times New Roman", 9, Font::Color::Value::RED);
    GlyphContext ctxt(times12);

    SUBCASE("insert")
    {
        GlyphColumn::Ptr c1 = factory.getColumn(),
                         c2 = factory.getColumn();

        GlyphCharacter::Ptr cha = factory.getCharacter('a'),
                            chb = factory.getCharacter('b');

        INFO("c1: " << c1->to_string());
        INFO("c2: " << c2->to_string());
        INFO("typeid(c1) == typeid(GlyphColumn): " << (typeid(*c1) == typeid(GlyphColumn)) );
        INFO("c1.equal(c2): " << (c1->equal(*c2)));

        CHECK_EQ(true, c1->equal(*c2));
        c1->insert(cha, ctxt);
        INFO("c1.equal(c2): " << (c1->equal(*c2)));


        CHECK_EQ(false, c1->equal(*c2));
    }
}
