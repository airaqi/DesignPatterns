#include "graphic_rectangle.hpp"
#include "coord.h"
#include "point.h"
#include <iostream>

GraphicRectangle::GraphicRectangle(Rect rect) : _rect(rect) {}
GraphicRectangle::GraphicRectangle(Point p1, Point p2) : _rect(p1, p2) {}
GraphicRectangle::GraphicRectangle(Coord x, Coord y, Coord w, Coord h) : _rect(x, y, w, h) {}

GraphicRectangle::~GraphicRectangle()
{
}

void GraphicRectangle::move(Point p)
{
    _rect.moveBy(p);
}

void GraphicRectangle::display()
{
    std::cout << "Rectangle: " << _rect << ", " << center() << "\n";
}

void GraphicRectangle::print(const char *prefix)
{
    std::cout << prefix << "(Rectangle: " << _rect << ", " << center() << ")\n";
}

bool GraphicRectangle::contains(Point &p)
{
    return _rect.contains(p);
}

Point GraphicRectangle::center()
{
    _center = _rect.center();
    return _center;
}
