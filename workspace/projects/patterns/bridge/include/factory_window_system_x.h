#ifndef __X_WINDOW_SYSTEM_FACTORY_H__
#define __X_WINDOW_SYSTEM_FACTORY_H__ 

#include "factory_window_system.h"
#include "window_imp.h"

class WindowSystemFactoryX : public WindowSystemFactory
{
    public:
        static const char* NAME;

        virtual ~WindowSystemFactoryX();

        static WindowSystemFactory* instance();
        static void destroy();

        virtual WindowImp* createWindow();

    protected:
        WindowSystemFactoryX();

    private:
        static WindowSystemFactory* _instance;
};

#endif /* ifndef __X_WINDOW_SYSTEM_FACTORY_H__ */
