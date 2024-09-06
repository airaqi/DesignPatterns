#ifndef __SHAPE_H__
#define __SHAPE_H__ 

#include "manipulator.hpp"
#include "point.h"
#include <ostream>
#include <string>

class Shape
{
    public:
        Shape() {}

        virtual void setBoundingBox(Point&, Point&) = 0;
        virtual void boundingBox(Point& bottomLeft, Point& topRight) const = 0;
        virtual Manipulator* createManipulator() = 0;
        virtual std::string to_string() = 0;

        friend std::ostream& operator<<(std::ostream& cout, Shape& shape) { cout << shape.to_string(); return cout; }
};

#endif /* ifndef __SHAPE_H__ */
