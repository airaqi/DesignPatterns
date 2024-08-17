#ifndef __WINDOW_SYSTEM_FACTORY_H__
#define __WINDOW_SYSTEM_FACTORY_H__ 

#include "window_imp.h"
#include <X11/X.h>

class WindowSystemFactory 
{
    public:
        virtual ~WindowSystemFactory() {}

        static WindowSystemFactory& instance();

        virtual WindowImp* createWindow() = 0;

    protected:
        WindowSystemFactory() {}

    private:
        static WindowSystemFactory* _instance;
};

#endif /* ifndef __WINDOW_SYSTEM_FACTORY_H__ */
