#include "doctest_main.h"
#include "glyph_character.h"
#include "glyph_column.h"
#include "glyph_rectangle.h"
#include "glyph_row.h"

TEST_CASE("Testing GlyphColumn")
{
    GlyphColumn c01;
    GlyphRow r01;
    GlyphCharacter ch01('a');
    GlyphRectangle rec1(Rect(10, 10, 100, 100));

    SUBCASE("append")
    {

        CHECK_EQ(0, c01.count());
        c01.append(&rec1);
        CHECK_EQ(1, c01.count());
        r01.append(&ch01);
        c01.append(&r01);

        CHECK_EQ(2, c01.count());
    }

    SUBCASE("isLeaf")
    {
        CHECK_EQ(false, c01.isLeaf());
    }

    SUBCASE("isComposite")
    {
        CHECK_EQ(true, c01.isComposite());
    }
}
