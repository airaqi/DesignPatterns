#ifndef __TEXT_VIEW_H__
#define __TEXT_VIEW_H__ 

#include "visual_component.h"
class TextView : public VisualComponent
{
    public:
        TextView();
        virtual ~TextView();

        virtual void draw();
        virtual void resize();
};

#endif /* ifndef __TEXT_VIEW_H__ */
