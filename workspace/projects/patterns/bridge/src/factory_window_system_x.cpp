#include "factory_window_system_x.h"
#include "factory_window_system.h"
#include "window_imp.h"
#include "window_imp_x.h"

const char* WindowSystemFactoryX::NAME = "XLib";
WindowSystemFactory* WindowSystemFactoryX::_instance = nullptr;

WindowSystemFactory* WindowSystemFactoryX::instance()
{
    if (_instance == nullptr)
        _instance = new WindowSystemFactoryX();
    return _instance;
}

WindowImp* WindowSystemFactoryX::createWindow()
{
    return new WindowImpX();
}


