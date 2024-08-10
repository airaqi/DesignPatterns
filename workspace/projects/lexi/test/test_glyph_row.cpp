#include "doctest_main.h"
#include "glyph_character.h"
#include "glyph_row.h"

TEST_CASE("Test GlyphRow") {
    GlyphRow row;
    GlyphCharacter ch01;
    GlyphCharacter ch02('a');

    row.insert(&ch01, 0);
    row.insert(&ch02, 1);

    SUBCASE("isLeaf") {
        CHECK_EQ(false, row.isLeaf());
    } 

    SUBCASE("isComposite") {
        CHECK_EQ(true, row.isComposite());
    }

    SUBCASE("insert") {
        row.insert(&ch01, 0);
        CHECK_EQ(&ch01, row.child(0));
        CHECK_EQ(&row, row.child(0)->parent());
    }

    SUBCASE("remove") {
        row.insert(&ch01, 0);
        row.insert(&ch02, 1);

        row.remove(&ch01);
        CHECK_EQ(&ch02, row.child(0));
    }

}

