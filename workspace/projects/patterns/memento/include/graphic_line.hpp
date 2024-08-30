#ifndef __GRAPHIC_LINE_H__
#define __GRAPHIC_LINE_H__ 

#include "coord.h"
#include "graphic.hpp"
#include "line.hpp"

class GraphicLine : public Graphic
{
    public:
        GraphicLine(Point, Point);
        GraphicLine(Coord x1, Coord y1, Coord x2, Coord y2);
        virtual ~GraphicLine();

        virtual void move(Point) override;
        virtual void display() override;
        virtual void print(const char* = "") override;

        virtual bool contains(Point &) override;
        virtual Point center() override;

    private:
        Line _line;
};

#endif /* ifndef __GRAPHIC_LINE_H__ */
