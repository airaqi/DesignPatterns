#ifndef __GRAPHIC_CANVAS_H__
#define __GRAPHIC_CANVAS_H__ 

#include "graphic.hpp"
#include "list.h"
#include "point.h"
#include "rect.h"

class GraphicCanvas : public Graphic
{
    public:
        GraphicCanvas(Rect);
        GraphicCanvas(Coord, Coord, Coord, Coord);
        virtual ~GraphicCanvas();

        virtual void add(Graphic*);
        virtual void remove(Graphic*);
        virtual Graphic* get(int);
        virtual Graphic* get(Point&);

        virtual bool contains(Point&) override;

        virtual void move(Point) override;
        virtual void display() override;
        virtual void print(const char* = "") override;

        virtual Point center() override;

    private:
        List<Graphic*> _children;
        Rect _rect;
};

#endif /* ifndef __GRAPHIC_CANVAS_H__ */
