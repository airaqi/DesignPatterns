#ifndef __VIEW_STRING_H__
#define __VIEW_STRING_H__ 

#include "point.h"
#include "view.h"

class ViewString : public View
{
    public: 
        ViewString(const char*, Point&);
        virtual ~ViewString();

        void draw(BWindow *) override;

    private:
        const char* _value;
        Point* _location;
};

#endif /* ifndef __VIEW_STRING_H__ */
