#include "factory_window_system.h"
#include "factory_window_system_x.h"
#include <unordered_map>

WindowSystemFactory* WindowSystemFactory::_instance = nullptr;
const char* WindowSystemFactory::_default_factory = WindowSystemFactoryX::NAME;
std::unordered_map<const char*, WindowSystemFactory*> WindowSystemFactory::_registry;


WindowSystemFactory::WindowSystemFactory() {}
WindowSystemFactory::~WindowSystemFactory() {}

WindowSystemFactory& WindowSystemFactory::instance(const char* name)
{
    if (!name) name = _default_factory;

     if (_instance == nullptr)
         _instance = _registry.at(name);
     return *_instance;
}

void WindowSystemFactory::subscribe(const char *name, WindowSystemFactory* factory) 
{
    _registry[name] = factory;
}

void WindowSystemFactory::unsubscribe(const char* name)
{
    _registry.erase(name);
}

void WindowSystemFactory::destroy()
{
    /*for (auto& it : _registry)
        unsubscribe(it.first);*/
    delete _instance;
    _instance = nullptr;
}

const char* WindowSystemFactory::defaultFactory()
{
    return _default_factory;
}

void WindowSystemFactory::defaultFactory(const char* name)
{
    _default_factory = name;
}
