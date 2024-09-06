#ifndef __MANIPULATOR_H__
#define __MANIPULATOR_H__ 

#include "point.h"
class Shape;

class Manipulator
{
    public:
        Manipulator(Shape* shape = nullptr) : _shape(shape) {}
        virtual ~Manipulator() {}

        virtual void move(const Point&) = 0;

    protected:
        Shape *_shape;
};

#endif /* ifndef __MANIPULATOR_H__ */
