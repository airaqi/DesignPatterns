#include "doctest_main.h"
#include "graphic_line.hpp"

TEST_CASE("Test Graphic Line") 
{
    Point p1(2, 4);
    Point p2(4, 8);
    Point p3(6, 12);

    GraphicLine l1(p1, p2);
    GraphicLine l2(p1, p3);
    GraphicLine l3(p3, p1);
    GraphicLine l4(p2, p1);

    CHECK_EQ(true, l2.contains(p2));
    CHECK_EQ(false, l1.contains(p3));
    CHECK_EQ(true, l3.contains(p2));
    CHECK_EQ(false, l4.contains(p3));

}
