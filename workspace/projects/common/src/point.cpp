#include "point.h"
#include "coord.h"
#include <cmath>
#include <istream>
#include <ostream>
#include <stdexcept>
#include <string>

const Point Point::Zero;

Point::Point(Coord x, Coord y) : _x(x), _y(y) {}

Coord Point::x() const { return _x; }
void Point::x(Coord x) { _x = x; }

Coord Point::y() const { return _y; }
void Point::y(Coord y) { _y = y; }

Coord Point::distance(const Point& p) const
{
    return std::sqrt(std::pow(x() - p.x(), 2) + std::pow(y() - p.y(), 2));
}

Point& Point::operator+=(const Point& p)
{
    x(x() + p.x());
    y(y() + p.y());
    return *this;
}

Point& Point::operator-=(const Point& p)
{
    x(x() - p.x());
    y(y() - p.y());
    return *this;
}

Point& Point::operator*=(const Point& p)
{
    x(x() * p.x());
    y(y() * p.y());
    return *this;
}

Point& Point::operator/=(const Point& p)
{
    if (p.x() == 0 || p.y() == 0)
        throw std::runtime_error(ERR_DIVIDE_BY_ZERO);
    x(x() / p.x());
    y(y() / p.y());

    return *this;
}

Point Point::operator-()
{
    return Point(-(x(), -y()));
}

std::string Point::to_string() const
{
    return "(" + std::to_string(x()) + ", " + std::to_string(y()) + ")";
}
// Friend functions
Point operator+(const Point& p1, const Point& p2)
{
    Point ret(p1);
    ret += p2;
    return ret;
}

Point operator-(const Point& p1, const Point& p2)
{
    Point ret(p1);
    ret -= p2;
    return ret;
}

Point operator*(const Point& p1, const Point& p2)
{
    Point ret(p1);
    ret *= p2;
    return ret;
}

Point operator/(const Point& p1, const Point& p2)
{
    Point ret(p1);
    ret /= p2;
    return ret;
}

bool operator==(const Point& p1, const Point& p2)
{
    return (p1.x() == p2.x() && p1.y() == p2.y());
}

bool operator!=(const Point& p1, const Point& p2) 
{
    return (p1.x() != p2.x() && p1.y() != p2.y());
}

std::ostream& operator<<(std::ostream& sout, const Point& p)
{
    sout << p.to_string();
    return sout;
}

std::istream& operator>>(std::istream& in, const Point& p)
{
    in >> p._x >> p._y;
    return in;
}
