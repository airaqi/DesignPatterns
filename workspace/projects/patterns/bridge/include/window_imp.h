#ifndef __WINDOWIMP_H__
#define __WINDOWIMP_H__ 

#include "point.h"

class WindowImp 
{
    public:
        virtual void impTop() = 0;
        virtual void impBottom() = 0;
        virtual void impSetExtent(const Point&) = 0;
        virtual void impSetOrigin(const Point&) = 0;

        virtual void deviceRect(Coord, Coord, Coord, Coord) = 0;
        virtual void deviceText(const char*, Coord, Coord) = 0;
        virtual void deviceBitMap(const char*, Coord, Coord) = 0;
        // any many more functions for drawing in windows ...

    protected:
        WindowImp();
};

#endif /* ifndef __WINDOWIMP_H__ */
