#ifndef __GRAPHIC_CONNECT_H__
#define __GRAPHIC_CONNECT_H__ 

#include "graphic.hpp"

class GraphicConnect : public Graphic
{
    public:
        GraphicConnect(Graphic* start, Graphic* end);
        virtual ~GraphicConnect();

        virtual void move(Point) override;
        virtual void display() override;
        virtual void print(const char* = "") override;

        virtual bool contains(Point &) override;
        virtual Point center() override;

    private:
        Graphic* _start;
        Graphic* _end;
        Graphic* _line;
};

#endif /* ifndef __GRAPHIC_CONNECT_H__ */
