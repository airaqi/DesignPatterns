#include "factory_window_system_x.h"
#include "factory_window_system.h"
#include "window_imp.h"
#include "window_imp_x.h"
#include <iostream>

const char* WindowSystemFactoryX::NAME = "XLib";
WindowSystemFactory* WindowSystemFactoryX::_instance = nullptr;

WindowSystemFactoryX::WindowSystemFactoryX() {}

WindowSystemFactoryX::~WindowSystemFactoryX() {}

WindowSystemFactory* WindowSystemFactoryX::instance()
{
    if (_instance == nullptr)
        _instance = new WindowSystemFactoryX();

    return _instance;
}

void WindowSystemFactoryX::destroy()
{
    //if (_instance)
        delete _instance;
    _instance = nullptr;
}

WindowImp* WindowSystemFactoryX::createWindow()
{
    return new WindowImpX();
}


