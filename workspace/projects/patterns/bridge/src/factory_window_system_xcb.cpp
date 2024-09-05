#include "factory_window_system_xcb.h"
#include "window_imp_xcb.h"
#include <iostream>

const char* WindowSystemFactoryXcb::NAME = "Xcb";

WindowSystemFactory* WindowSystemFactoryXcb::_instance = nullptr;

WindowSystemFactoryXcb::WindowSystemFactoryXcb() {}
WindowSystemFactoryXcb::~WindowSystemFactoryXcb() {}

WindowSystemFactory* WindowSystemFactoryXcb::instance()
{
    if (_instance == nullptr)
        _instance = new WindowSystemFactoryXcb();
    return _instance;
}

void WindowSystemFactoryXcb::destroy()
{
    if (_instance != nullptr)
        delete _instance;
    _instance = nullptr;
}

WindowImp* WindowSystemFactoryXcb::createWindow()
{
    return new WindowImpXcb();
}
