#include "doctest_main.h"
#include "glyph_character.h"
#include "point.h"

TEST_CASE("Test GlyphCharacter") {
    GlyphCharacter ch00;
    GlyphCharacter ch01('a');
    GlyphCharacter ch02('b');
    GlyphCharacter ch03('c', 100, 100);

    SUBCASE("intersects") {
        Point p1(0, 0);
        Point p2(100, 100);

        CHECK_EQ(true, ch00.intersects(p1));
        CHECK_EQ(true, ch00.intersects(p1));
        CHECK_EQ(false, ch00.intersects(p2));
        CHECK_EQ(false, ch02.intersects(p2));
        CHECK_EQ(true, ch03.intersects(p2));
    }
}    
