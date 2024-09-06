#ifndef __TEXT_VIEW_H__
#define __TEXT_VIEW_H__ 
#include "coord.h"
#include <cstring>
#include <iostream>

class TextView
{
    public:
        TextView(Coord x = 0, Coord y = 0, Coord w = 0, Coord h = 0, const char *text = "") : 
            _x(x), _y(y), _width(w), _height(h), _text(text) {}

        void setOrigin(const Coord& x, const Coord &y) { _x = x; _y = y; }
        void setExtent(const Coord& width, const Coord& height) { _width = width; _height = height; }
        void setText(const char* text) { _text = text; }
        const char* getText() { return _text; }

        void getOrigin(Coord& x, Coord& y) const { x = _x; y = _y; }
        void getExtent(Coord& width, Coord& height) const { width = _width; height = _height; }
        virtual bool isEmpty() const { return ((_height - _y) && (_x - _width)) || std::strcmp(_text, ""); }

        void doSomthing() { std::cout << "(" << _x << ", " << _y << "), (" << _width << ", " << _height << ") : " << _text << "\n"; }

    private:
        Coord _x;
        Coord _y;
        Coord _width;
        Coord _height;
        const char* _text;
};

#endif /* ifndef __TEXT_VIEW_H__ */
