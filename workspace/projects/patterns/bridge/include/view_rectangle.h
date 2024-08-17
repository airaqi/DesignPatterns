#ifndef __VIEW_RECTANGLE_H__
#define __VIEW_RECTANGLE_H__ 

#include "rect.h"
#include "view.h"

class ViewRectangle : public View
{
    public:
        ViewRectangle(Rect& r);
        virtual ~ViewRectangle();
       
        void draw(BWindow *) override;

    private:
        Rect* _rect;
};

#endif /* ifndef __VIEW_RECTANGLE_H__ */
