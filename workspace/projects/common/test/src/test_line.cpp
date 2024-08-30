#include "doctest_main.h"
#include "line.hpp"
#include "point.h"
#include <cmath>

TEST_CASE("") {
    Line l1;
    Line l2(10, 10, 30, 30);
    Line l3(Point(20, 20), Point(50, 50));
    Line l4(Point(20, 50), Point(50, 20));
    Line l5(30, 30, 50, 50);
    Line l6(30, 30, 10, 10);

    SUBCASE("initialization") 
    {
        CHECK_EQ(Point::Zero, l1.start());
        CHECK_EQ(Point::Zero, l1.end());

        CHECK_EQ(Point(10, 10), l2.start());
        CHECK_EQ(Point(30, 30), l2.end());
    }

    SUBCASE("start")
    {
        CHECK_EQ(Point(10, 10), l2.start());
        Point p(10, 11);
        l2.start(p);
        CHECK_EQ(p, l2.start());
    }

    SUBCASE("end")
    {
        CHECK_EQ(Point(30, 30), l2.end());
        Point p(31, 31);
        l2.end(p);
        CHECK_EQ(p, l2.end());
    }

    SUBCASE("length")
    {
        CHECK_EQ(0, l1.length());
        CHECK((std::sqrt(800) - l2.length()) < 0.001);
        CHECK((sqrt(1800) - l3.length()) < 0.001);
    }

    SUBCASE("slope")
    {
        CHECK_EQ(true, std::isnan(l1.slope()));
        CHECK_EQ(1, l2.slope());
        CHECK_EQ(1, l3.slope());
        CHECK_EQ(-1, l4.slope());
    }

    SUBCASE("y_intercept")
    {
        CHECK_EQ(true, std::isnan(l1.y_intercept()));
        CHECK_EQ(0, l2.y_intercept());
        CHECK_EQ(70, l4.y_intercept());
    }

    SUBCASE("center")
    {
        CHECK_EQ(Point::Zero, l1.center());
        CHECK_EQ(Point(20, 20), l2.center());
        CHECK_EQ(Point(35, 35), l4.center());
    }

    SUBCASE("contains")
    {
        CHECK_EQ(false, l1.contains(Point::Zero));
        CHECK_EQ(false, l1.contains(Point(10, 10)));
        CHECK_EQ(true, l2.contains(Point(10, 10)));
        CHECK_EQ(true, l2.contains(Point(30, 30)));
        CHECK_EQ(true, l2.contains(Point(20, 20)));
        CHECK_EQ(false, l2.contains(Point(35, 35)));
        CHECK_EQ(true, l6.contains(Point(20, 20)));
    }

    SUBCASE("moveTo")
    {
        Point p1(30, 30);
        Point p2(5, 5);
        l2.moveTo(p1);
        CHECK_EQ(Line(30, 30, 50, 50), l2);
        l2.moveTo(p2);
        CHECK_EQ(Line(5, 5, 25, 25), l2);
    }

    SUBCASE("moveBy")
    {
        l2.moveBy(Point(10, 10));
        CHECK_EQ(Line(20, 20, 40, 40), l2);
        l2.moveBy(Point(-5, -5));
        CHECK_EQ(l2, Line(15, 15, 35, 35));
    }
}
