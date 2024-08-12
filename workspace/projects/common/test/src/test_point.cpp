#include "point.h"
#include <doctest/doctest.h>

TEST_CASE("Test Point")
{
    Point p1;
    Point p2(1, 2);
    Point p3(3, 4);
    Point p4(4, 6);
    Point p5(3, 8);

    SUBCASE("initialization")
    {
        CHECK_EQ(0, p1.x());
        CHECK_EQ(0, p1.y());

        CHECK_EQ(1, p2.x());
        CHECK_EQ(2, p2.y());
    }

    SUBCASE("operator+")
    {
        CHECK_EQ(p4, p2 + p3);
    }
    SUBCASE("operator-") {
        CHECK_EQ(p2, p4 - p3);
    }
    SUBCASE("operator*") {
        CHECK_EQ(p5, p2 * p3);
    }
    SUBCASE("operator/") {
        CHECK_EQ(p2, p5 / p3);
    }

    SUBCASE("operator+=") { }
    SUBCASE("operator-=") { }
    SUBCASE("operator*=") { }
    SUBCASE("operator/=") { }

    SUBCASE("operator<<") { }
    SUBCASE("operator>>") { }
}
