#ifndef __X_WINDOW_SYSTEM_FACTORY_H__
#define __X_WINDOW_SYSTEM_FACTORY_H__ 

#include "factory_window_system.h"
#include "window_imp.h"

class XWindowSystemFactory : public WindowSystemFactory
{
    public:
        virtual ~XWindowSystemFactory() {}

        static WindowSystemFactory* instance();

        virtual WindowImp* createWindow();

    protected:
        XWindowSystemFactory() {}
};

#endif /* ifndef __X_WINDOW_SYSTEM_FACTORY_H__ */
