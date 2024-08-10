#ifndef __DECORATOR_SCROLL_H__
#define __DECORATOR_SCROLL_H__ 

#include "decorator.h"
#include "visual_component.h"
class DecoratorScroll : public Decorator
{
    public:
        DecoratorScroll(VisualComponent*);

        virtual void draw();

    private:
        void draw_scroll();
};

#endif /* ifndef __DECORATOR_SCROLL_H__ */
