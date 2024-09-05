#ifndef __WINDOW_SYSTEM_FACTORY_H__
#define __WINDOW_SYSTEM_FACTORY_H__ 

#include "window_imp.h"
#include <X11/X.h>
#include <unordered_map>

class WindowSystemFactory 
{
    public:
        virtual ~WindowSystemFactory();

        static WindowSystemFactory& instance(const char* name = nullptr);
        static void destroy();

        static void subscribe(const char* name, WindowSystemFactory* fatory);
        static void unsubscribe(const char* name);

        static const char* defaultFactory();
        static void defaultFactory(const char* name);

        virtual WindowImp* createWindow() = 0;

    protected:
        WindowSystemFactory();

    protected:
        static WindowSystemFactory* _instance;

    private:
        static std::unordered_map<const char*, WindowSystemFactory*> _registry;
        static const char* _default_factory;
};

#endif /* ifndef __WINDOW_SYSTEM_FACTORY_H__ */
