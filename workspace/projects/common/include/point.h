#ifndef __POINT_H__
#define __POINT_H__ 

#include "coord.h"
#include <istream>
#include <ostream>

const std::string ERR_DIVIDE_BY_ZERO = "Divide by Zero";

class Point
{
    public:
        static const Point Zero;

        Point(Coord x = 0.0, Coord y = 0.0);
        Coord x() const; void x(Coord x);
        Coord y() const; void y(Coord y);

        Coord distance(const Point&) const;

        friend Point operator+(const Point&, const Point&);
        friend Point operator-(const Point&, const Point&);
        friend Point operator*(const Point&, const Point&);
        friend Point operator/(const Point&, const Point&);

        Point& operator+=(const Point&);
        Point& operator-=(const Point&);
        Point& operator*=(const Point&);
        Point& operator/=(const Point&);

        Point operator-();

        std::string to_string() const;

        friend bool operator==(const Point&, const Point&);
        friend bool operator!=(const Point&, const Point&);

        friend std::ostream& operator<<(std::ostream&, const Point&);
        friend std::istream& operator>>(std::istream&, const Point&);

    private:
        Coord _x;
        Coord _y;

};

#endif /* ifndef __POINT_H__ */
