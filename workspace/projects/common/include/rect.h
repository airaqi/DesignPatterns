#ifndef __RECT_H__
#define __RECT_H__ 

#include "coord.h"
#include "point.h"
#include <ostream>
#include <string>

/* 
 * Rect class
 * Holds a rectangle shape with top left Point, and a width and height.
 */
class Rect
{
    public:
        static const Rect Zero;

        Rect(Coord x = 0.0, Coord y = 0.0, Coord w = 0.0, Coord h = 0.0);
        Rect(const Point& origin, const Point& extent);

        Coord width() const;    void width(Coord);
        Coord height() const;   void height(Coord);
        Coord left() const;     void left(Coord);
        Coord right() const;    void right(Coord);
        Coord top() const;      void top(Coord);
        Coord bottom() const;   void bottom(Coord);

        Point& origin();        void origin(const Point&);
        Point& extent();        void extent(const Point&);

        void moveTo(const Point&);
        void moveBy(const Point&);

        bool isEmpty() const;
        bool contains(const Point&) const;
        bool intersects(const Rect&) const;
        
        Rect intersect(const Rect&);
        Rect combine(const Rect&);

        friend bool operator==(const Rect& lhs, const Rect& rhs);
        friend bool operator!=(const Rect& lhs, const Rect& rhs);

        friend std::ostream& operator<<(std::ostream&, const Rect&);

        std::string to_string() const;

    private:
        Point _origin;
        Point _extent;
};

#endif /* ifndef __RECT_H__ */
