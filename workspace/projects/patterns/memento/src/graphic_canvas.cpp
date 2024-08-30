#include "graphic_canvas.hpp"
#include "graphic.hpp"
#include "iterator.h"
#include <iostream>


GraphicCanvas::GraphicCanvas(Rect rect) : _rect(rect) {}

GraphicCanvas::GraphicCanvas(Coord x, Coord y, Coord w, Coord h) : _rect(x, y, w, h) {}

GraphicCanvas::~GraphicCanvas()
{
    Iterator<Graphic*>& i = _children.iterator();
    for (i.first(); !i.is_done(); i.next())
        delete i.currentItem();
}

void GraphicCanvas::add(Graphic* graphic)
{
    _children.append(graphic);
}


void GraphicCanvas::remove(Graphic* graphic)
{
    _children.remove(graphic);
}


Graphic* GraphicCanvas::get(int index)
{
    return _children.get(index);
}

Graphic* GraphicCanvas::get(Point& p)
{
    Iterator<Graphic*>& i = _children.iterator();
    for (i.first(); !i.is_done(); i.next())
        if (i.currentItem()->contains(p))
            return i.currentItem();
    return nullptr;
}


bool GraphicCanvas::contains(Point& p)
{
    Iterator<Graphic*>& i = _children.iterator();
    for (i.first(); !i.is_done(); i.next())
        if (i.currentItem()->contains(p))
            return true;
    return false;
}

void GraphicCanvas::move(Point p)
{}


void GraphicCanvas::display()
{
}

void GraphicCanvas::print(const char *prefix)
{
    std::cout << prefix << "(Canvas " << "(" << _rect << "):\n [";
    Iterator<Graphic*>& i = _children.iterator();
    for (i.first(); !i.is_done(); i.next())
        i.currentItem()->print("\t");
    std::cout << "])\n";
}


Point GraphicCanvas::center() 
{
    _center = _rect.center();
    return _center;
}


