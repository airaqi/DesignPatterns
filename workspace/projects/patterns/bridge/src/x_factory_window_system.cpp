#include "x_factory_window_system.h"
#include "factory_window_system.h"
#include "window_imp.h"
#include "x_window_imp.h"

WindowSystemFactory* XWindowSystemFactory::instance()
{
    return new XWindowSystemFactory();
}

WindowImp* XWindowSystemFactory::createWindow()
{
    return new XWindowImp();
}


