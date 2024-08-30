#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__ 

#include "point.h"

class Graphic
{
    public:
        Graphic() {}
        virtual ~Graphic() {}

        virtual void move(Point) = 0;
        virtual void display() = 0;
        virtual void print(const char* = "") = 0;

        virtual bool contains(Point&) = 0;
        virtual Point center() = 0;

    protected:
        Point _center;
};

#endif /* ifndef __GRAPHIC_H__ */
