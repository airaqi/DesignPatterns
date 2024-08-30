#ifndef __GRAPHIC_RECTANGLE_H__
#define __GRAPHIC_RECTANGLE_H__ 

#include "coord.h"
#include "graphic.hpp"
#include "point.h"
#include "rect.h"

class GraphicRectangle : public Graphic
{
    public:
        GraphicRectangle(Rect rect);
        GraphicRectangle(Point, Point);
        GraphicRectangle(Coord, Coord, Coord, Coord);

        virtual ~GraphicRectangle();

        virtual void move(Point) override;
        virtual void display() override;
        virtual void print(const char* = "") override;

        virtual bool contains(Point &) override;
        virtual Point center() override;

    private:
        Rect _rect;
};

#endif /* ifndef __GRAPHIC_RECTANGLE_H__ */
