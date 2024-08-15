#ifndef __APPLICATION_WINDOW_H__
#define __APPLICATION_WINDOW_H__ 

#include "window.h"

class ApplicationWindow : public Window
{
    public:
        ApplicationWindow(View* contents);

        virtual void drawContents();
};
#endif /* ifndef __APPLICATION_WINDOW_H__ */
