#ifndef __DECORATOR_BORDER_H__
#define __DECORATOR_BORDER_H__ 

#include "decorator.h"
#include "visual_component.h"
class DecoratorBorder : public Decorator
{
    public:
        DecoratorBorder(VisualComponent*,int);

        virtual void draw();

    private:
        void draw_border(int);

        int _width;
};

#endif /* ifndef __DECORATOR_BORDER_H__ */
