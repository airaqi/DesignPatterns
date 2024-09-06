#include "shape_text_object.hpp"
#include "manipulator_text.hpp"
#include <sstream>


TextShapeObject::TextShapeObject(TextView* view) : Shape(), _text(view) {}

void TextShapeObject::boundingBox(Point& bottomLeft, Point& topRight) const
{
    Coord x, y, w, h;
    _text->getOrigin(x, y);
    _text->getExtent(w, h);

    bottomLeft = Point(x, y + h);
    topRight = Point(x + w, y);
}


void TextShapeObject::setBoundingBox(Point& bottomLeft, Point& topRight)
{
    _text->setOrigin(bottomLeft.x(), topRight.y());
    _text->setExtent(topRight.x() - bottomLeft.x(), bottomLeft.y() - topRight.y());
}

Manipulator* TextShapeObject::createManipulator()
{
    return new TextManipulator(this);
}


bool TextShapeObject::isEmpty() const
{
    return _text->isEmpty();
}


void TextShapeObject::doSomthing()
{
    _text->doSomthing();
}


std::string TextShapeObject::to_string()
{
    std::stringstream sout;
    Point bl, tr;
    boundingBox(bl, tr);
    sout 
        << "[TextShapeObject - bottomLeft: " << bl 
        << " topRight: " << tr 
        << " text: " << _text->getText() 
        << "]";
    return sout.str();
}


