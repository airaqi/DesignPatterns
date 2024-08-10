#ifndef __VISUAL_COMPONENT_H__
#define __VISUAL_COMPONENT_H__ 

class VisualComponent
{
    public:
        VisualComponent() {}
        virtual ~VisualComponent() {}

        virtual void draw() = 0;
        virtual void resize() = 0;
};

#endif /* ifndef __VISUAL_COMPONENT_H__ */
