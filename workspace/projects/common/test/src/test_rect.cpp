#include "point.h"
#include "rect.h"
#include <doctest/doctest.h>
#include <iostream>

TEST_CASE("Testing Rect") {
    Point p1(1,2);
    Point p2(3,4);
    Point p3(10, 10);
    Point p4(11, 12);
    Point p5(2, 2);
    Point p6(4, 6);
    Point p7(2,3);
    Point p8(5, 7);
    Point p9 = p2 + p3;

    Rect r0;
    Rect r1(1,2,3,4);
    Rect r2(p1,p1 + p2);
    Rect r3(p7, p4);
    Rect r4(p3, p3 + p2);
    Rect r5(p7, p6);
    Rect r6(p1, p4);

    SUBCASE("width") {
        CHECK_EQ(0, r0.width());
        CHECK_EQ(3, r1.width());
        CHECK_EQ(3, r2.width());

        r1.width(4);
        CHECK_EQ(4, r1.width());
    }

    SUBCASE("height") {
        CHECK_EQ(0, r0.width());
        CHECK_EQ(4, r1.height());
        CHECK_EQ(4, r2.height());

        r1.height(5);
        CHECK_EQ(5, r1.height());
    }

    SUBCASE("left") {
        CHECK_EQ(0, r0.left());
        CHECK_EQ(1, r1.left());
        CHECK_EQ(1, r2.left());

        r1.left(2);
        CHECK_EQ(2, r1.left());
    }

    SUBCASE("right") {
        CHECK_EQ(0, r0.right());
        CHECK_EQ(4, r1.right());
        CHECK_EQ(4, r2.right());

        r1.right(5);
        CHECK_EQ(5, r1.right());
        CHECK_EQ(4, r1.width());
    }

    SUBCASE("top") {
        CHECK_EQ(0, r0.top());
        CHECK_EQ(2, r1.top());
        CHECK_EQ(2, r2.top());

        r1.top(3);
        CHECK_EQ(3, r1.top());
    }
    SUBCASE("bottom") {
        CHECK_EQ(0, r0.bottom());
        CHECK_EQ(6, r1.bottom());
        CHECK_EQ(6, r2.bottom());

        r1.bottom(9);
        CHECK_EQ(9, r1.bottom());
        CHECK_EQ(7, r1.height());
    }
    SUBCASE("origin") {
        CHECK_EQ(p1, r1.origin());
        CHECK_EQ(p1, r2.origin());
    }
    SUBCASE("extent") {
        CHECK_EQ(p6, r1.extent());
        CHECK_EQ(p6, r2.extent());
    }
    SUBCASE("moveTo") {
        r1.moveTo(p3);
        CHECK_EQ(p3, r1.origin());
        CHECK_EQ(p9, r1.extent());
    }
    SUBCASE("moveBy") {
        r1.moveBy(p3);
        CHECK_EQ(p4, r1.origin());
    }
    SUBCASE("isEmpty") {}
    SUBCASE("contains") {
        CHECK_EQ(true, r1.contains(p5));
        CHECK_EQ(false, r1.contains(p3));
    }

    SUBCASE("intersets") {
        CHECK_EQ(true, r2.intersects(r3));
        CHECK_EQ(false, r2.intersects(r4));
    } 

    SUBCASE("intersect") {
        CHECK_EQ(r5, r2.intersect(r3));
        CHECK_EQ(r0, r2.intersect(r4));
    }

    SUBCASE("combine") {
        CHECK_EQ(r6, r2.combine(r3));
    }

}
