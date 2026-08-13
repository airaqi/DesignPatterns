#include "font.hpp"
#include "doctest_main.h"
#include "glyph_factory.hpp"
#include <string>

TEST_CASE("font")
{
    GlyphFactory factory = GlyphFactory::get();

    SUBCASE("init")
    {
        Font::Ptr font = factory.getFont("Times New Roman", 12);
        CHECK_EQ("Times-New-Roman-12-RESET", font->fullname());
        CHECK_EQ(Font::Color::Value::RESET, font->getColor());
        CHECK_EQ("RESET", font->getColor().to_string());
        CHECK_EQ("\033[0m", font->getColor().to_code());
    }

    SUBCASE("init color")
    {
        Font::Ptr font = factory.getFont("Times New Roman", 12, Font::Color::Value::RED);
        CHECK_EQ("Times-New-Roman-12-RED", font->fullname());
        CHECK_EQ(Font::Color::Value::RED, font->getColor());
        CHECK_EQ("RED", font->getColor().to_string());
        CHECK_EQ("\033[0;31m", font->getColor().to_code());
    }

    SUBCASE("Equality")
    {
        std::string timesname = "Times New Roman";
        Font times12(timesname, 12),
             times122(timesname, 12),
             times9(timesname, 9);

        Font::Ptr ptimes12 = factory.getFont(timesname, 12),
            ptimes122 = factory.getFont(timesname, 12),
            ptimes9 = factory.getFont(timesname, 9);

        CHECK_EQ(true, (times12 == times122));
        CHECK_EQ(false, (times12 == times9));

        CHECK_EQ(true, (ptimes12 == ptimes122));
        CHECK_EQ(false, (ptimes12 == ptimes9));
    }
}
