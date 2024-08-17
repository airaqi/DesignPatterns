#include "factory_window_system.h"
#include "x_factory_window_system.h"

WindowSystemFactory* WindowSystemFactory::_instance = nullptr;

WindowSystemFactory& WindowSystemFactory::instance()
{
     if (_instance == nullptr)
         _instance = XWindowSystemFactory::instance();
     return *_instance;
}


