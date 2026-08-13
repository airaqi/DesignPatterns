#include "doctest_main.h"
#include "glyph_character.hpp"
#include "glyph_factory.hpp"
#include <string>

TEST_CASE("GlyphCharacter")
{
    GlyphFactory factory = GlyphFactory::get();

    SUBCASE("init")
    {
        GlyphCharacter::Ptr cha = factory.getCharacter('a'),
                            chb = factory.getCharacter('b'),
                            chnl = factory.getCharacter('\n'),
                            chtb = factory.getCharacter('\t');

        CHECK_EQ('a', cha->character());
        CHECK_EQ('b', chb->character());
        CHECK_EQ('\n', chnl->character());
        CHECK_EQ('\t', chtb->character());

        CHECK_EQ("a", cha->to_string());
        CHECK_EQ("a", cha->to_string(true));
        CHECK_EQ("b", chb->to_string());
        CHECK_EQ("b", chb->to_string(true));
        CHECK_EQ("↲", chnl->to_string());
        CHECK_EQ("\n", chnl->to_string(true));
        CHECK_EQ("↦", chtb->to_string());
        CHECK_EQ("\t", chtb->to_string(true));
     }

    SUBCASE("Equality")
    {
        GlyphCharacter::Ptr ch = GlyphFactory::get().getCharacter('a'),
                            ch2 = GlyphFactory::get().getCharacter('a'),
                            chb = GlyphFactory::get().getCharacter('b');
        CHECK_EQ(true, ch == ch2);
        CHECK_EQ(false, ch == chb);
        CHECK_EQ(true, ch != chb);
    }
}
