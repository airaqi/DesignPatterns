#ifndef __DECORATOR_H__
#define __DECORATOR_H__ 

#include "visual_component.h"
class Decorator : public VisualComponent
{
    public:
        Decorator(VisualComponent*);
        virtual ~Decorator();

        virtual void draw();
        virtual void resize();

    private:
        VisualComponent* _component;
};

#endif /* ifndef __DECORATOR_H__ */
