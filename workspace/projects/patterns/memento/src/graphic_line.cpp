#include "graphic_line.hpp"
#include "point.h"
#include <iostream>

GraphicLine::GraphicLine(Point start, Point end) : _line(start, end)
{
}

GraphicLine::GraphicLine(Coord x1, Coord y1, Coord x2, Coord y2) : _line(x1, y1, x2, y2)
{
}

GraphicLine::~GraphicLine()
{
}

void GraphicLine::move(Point p)
{
    _line.moveBy(p);
}

void GraphicLine::display()
{
}

void GraphicLine::print(const char *prefix)
{
    std::cout << prefix << _line << "\n";
}

bool GraphicLine::contains(Point &p)
{
    return _line.contains(p);
}

Point GraphicLine::center()
{
    return _line.center();
}
