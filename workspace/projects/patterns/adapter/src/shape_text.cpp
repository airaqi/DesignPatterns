#include "shape_text.hpp"
#include "coord.h"
#include "manipulator_text.hpp"
#include "text_view.hpp"
#include <sstream>


TextShapeClass::TextShapeClass(Point& bottomLeft, Point& topRight) : 
    TextView(bottomLeft.x(), topRight.y(), topRight.x() - bottomLeft.x(), bottomLeft.y() - topRight.y()) {}


TextShapeClass::TextShapeClass(Point& bottomLeft, Point& topRight, const char* text) : 
    TextView(bottomLeft.x(), topRight.y(), topRight.x() - bottomLeft.x(), bottomLeft.y() - topRight.y(), text)
{
}


void TextShapeClass::setBoundingBox(Point& bottomLeft, Point& topRight) 
{
    TextView::setOrigin(bottomLeft.x(), topRight.y());
    TextView::setExtent(topRight.x() - bottomLeft.x(), bottomLeft.y() - topRight.y());
}

void TextShapeClass::boundingBox(Point &bottomLeft, Point &topRight) const
{
    Coord top, left, width, height;

    getOrigin(left, top);
    getExtent(width, height);

    bottomLeft = Point(left, top + height);
    topRight = Point(left + width, top);
}


Manipulator* TextShapeClass::createManipulator() 
{
    return new TextManipulator(this);
}


bool TextShapeClass::isEmpty() const
{
    return TextView::isEmpty();
}


void TextShapeClass::doSomthing()
{
    TextView::doSomthing();
}


std::string TextShapeClass::to_string()
{
    std::stringstream sout;
    Point bl, tr;
    boundingBox(bl, tr);

    sout << "[TextShapeClass - bottom Left: " << bl 
        << " top right: " << tr
        << " text: " << TextView::getText()
        << "]";

    return sout.str();
}
