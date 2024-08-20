#include "factory_window_system_xcb.h"
#include "window_imp_xcb.h"

const char* WindowSystemFactoryXcb::NAME = "Xcb";

WindowSystemFactory* WindowSystemFactoryXcb::_instance = nullptr;

WindowSystemFactory* WindowSystemFactoryXcb::instance()
{
    if (_instance == nullptr)
        _instance = new WindowSystemFactoryXcb();
    return _instance;
}

WindowImp* WindowSystemFactoryXcb::createWindow()
{
    return new WindowImpXcb();
}
