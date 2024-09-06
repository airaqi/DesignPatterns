#ifndef __SHAPE_TEXT_H__
#define __SHAPE_TEXT_H__ 

#include "point.h"
#include "shape.hpp"
#include "text_view.hpp"
#include <string>

class TextShapeClass : public Shape, private TextView
{
    public:
        TextShapeClass(Point& bottomLeft, Point& topRight);
        TextShapeClass(Point& bottomLeft, Point& topRight, const char*);

        virtual void setBoundingBox(Point& bottomLeft, Point& topRight) override;

        virtual void boundingBox(Point &bottomLeft, Point &topRight) const override;
        virtual Manipulator * createManipulator() override;
        virtual bool isEmpty() const override;

        virtual void doSomthing();

        virtual std::string to_string() override;
};

#endif /* ifndef __SHAPE_TEXT_H__ */
