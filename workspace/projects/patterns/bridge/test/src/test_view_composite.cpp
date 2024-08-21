#include "doctest_main.h"
#include "factory_window_system.h"
#include "point.h"
#include "rect.h"
#include "view_composite.h"
#include "view_rectangle.h"
#include "view_string.h"

TEST_CASE("Test View Composite")
{
    Rect r(10, 10, 100, 50);
    ViewRectangle rect(r);
    Point p1(20, 40);
    Point p2(60, 190);
    Point p3(60, 150);
    ViewString msg("<<<< Press ESC to exit! >>>>", p2);
    ViewString str("Hello Bridge!", p1);
    ViewString ws(WindowSystemFactory::defaultFactory(), p3);
    ViewComposite composite;

    composite.append(&rect);
    composite.append(&str);
    composite.append(&msg);
    composite.append(&ws);


    CHECK_EQ(&rect, composite.get_child(0));
    CHECK_EQ(&str, composite.get_child(1));
    CHECK_EQ(&msg, composite.get_child(2));
    CHECK_EQ(&ws, composite.get_child(3));


}
