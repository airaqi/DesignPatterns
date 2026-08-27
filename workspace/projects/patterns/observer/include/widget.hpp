#ifndef __WIDGET_H__
#define __WIDGET_H__ 

#include "window.hpp"
#include <memory>

class Widget : public Window
{
    public:
        using Ptr = std::shared_ptr<Widget>;

        virtual void draw() = 0;
};

#endif /* ifndef __WIDGET_H__ */
