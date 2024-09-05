#ifndef __WINDOW_SYSTEM_FACTORY_XCB_H__
#define __WINDOW_SYSTEM_FACTORY_XCB_H__ 

#include "factory_window_system.h"
#include "window_imp.h"

class WindowSystemFactoryXcb : public WindowSystemFactory
{
    public:
        static const char* NAME;

        virtual ~WindowSystemFactoryXcb();

        static WindowSystemFactory* instance();
        static void destroy();

        virtual WindowImp* createWindow();

    protected:
        WindowSystemFactoryXcb();

    private:
        static WindowSystemFactory* _instance;
};

#endif /* ifndef __WINDOW_SYSTEM_FACTORY_XCB_H__ */
