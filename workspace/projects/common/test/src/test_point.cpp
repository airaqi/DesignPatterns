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

    SUBCASE("distance") 
    {
        CHECK((std::sqrt(5) -  p1.distance(p2)) < 0.001);
        CHECK_EQ(5, p1.distance(p3));
        CHECK((std::sqrt(52) - p1.distance(p4)) < 0.001);
        CHECK((std::sqrt(73) - p1.distance(p5)) < 0.001);
        CHECK((std::sqrt(8) - p2.distance(p3)) < 0.001);
        CHECK((std::sqrt(8) - p3.distance(p2)) < 0.001);
        CHECK((std::sqrt(40) - p2.distance(p5)) < 0.001);
        CHECK((std::sqrt(40) - p5.distance(p2)) < 0.001);
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
