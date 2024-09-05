#include "factory_window_system.h"
#include "factory_window_system_x.h"
#include "factory_window_system_xcb.h"
#include "point.h"
#include "view_composite.h"
#include "view_rectangle.h"
#include "view_string.h"
#include "window_application.h"
#include <cstring>
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Hello Bridge Pattern!\n";

    //std::cout << argc << " " << argv[0] << " " << argv[1] << " " << WindowSystemFactoryXcb::NAME << "\n";

    WindowSystemFactory::subscribe(WindowSystemFactoryX::NAME, WindowSystemFactoryX::instance());
    WindowSystemFactory::subscribe(WindowSystemFactoryXcb::NAME, WindowSystemFactoryXcb::instance());
    //WindowSystemFactory::defaultFactory(WindowSystemFactoryXcb::NAME);

    if (argc > 1 && !std::strcmp(argv[1], WindowSystemFactoryXcb::NAME)) 
        WindowSystemFactory::defaultFactory(WindowSystemFactoryXcb::NAME);
    else if (argc > 1 && !std::strcmp(argv[1], WindowSystemFactoryX::NAME))
        WindowSystemFactory::defaultFactory(WindowSystemFactoryX::NAME);
    else if (argc > 1)
    {
        std::cout << "USAGE: bridgeapp [XLib | Xcb]\n";
        return -1;
    }

    std::cout << "defaultFactory: " << WindowSystemFactory::defaultFactory() << "\n";

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

    WindowApplication window(&composite);
    window.run_loop();

    //WindowImp* imp = WindowSystemFactory::instance().createWindow();
    std::cout << "main end\n";

    //WindowSystemFactory::destroy();
    WindowSystemFactoryX::destroy();
    WindowSystemFactoryXcb::destroy();

    //WindowSystemFactory::unsubstribe(WindowSystemFactoryX::NAME);
    //WindowSystemFactory::unsubstribe(WindowSystemFactoryXcb::NAME);


    return 0;
}
