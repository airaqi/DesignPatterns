#include "manipulator_text.hpp"
#include "shape.hpp"

TextManipulator::TextManipulator(Shape* shape) : Manipulator(shape)
{
}

void TextManipulator::move(const Point &to)
{
    Point bl, tr;
    _shape->boundingBox(bl, tr);
    bl += to;
    tr += to;
    _shape->setBoundingBox(bl, tr);
}


