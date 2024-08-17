#include "point.h"
#include "view_composite.h"
#include "view_rectangle.h"
#include "view_string.h"
#include "window_application.h"
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Hello Bridge Pattern!\n";

    Rect r(10, 10, 100, 50);
    ViewRectangle rect(r);
    Point p1(30, 40);
    Point p2(50, 190);
    ViewString msg("<<<< Press Esc to close window! >>>>", p2);
    ViewString str("Hello Bridge!", p1);
    ViewComposite composite;

    composite.append(&rect);
    composite.append(&str);
    composite.append(&msg);

    WindowApplication window(&composite);
    window.run_loop();

    //WindowImp* imp = WindowSystemFactory::instance().createWindow();

    return 0;
}
