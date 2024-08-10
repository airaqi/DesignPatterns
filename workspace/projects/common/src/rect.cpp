#include "rect.h"
#include "coord.h"
#include <algorithm>
#include <ostream>
#include <string>

Rect::Rect(Coord x, Coord y, Coord w, Coord h) : Rect(Point(x, y), Point(x+w, y+h)) {}

Rect::Rect(const Point& o, const Point& e) : _origin(o), _extent(e) {}

Coord Rect::width() const { return _extent.x() - _origin.x(); }
void Rect::width(Coord w) { _extent.x(_origin.x() + w); }

Coord Rect::height() const { return _extent.y() - _origin.y(); }
void Rect::height(Coord h) { _extent.y(_origin.y() + h); }

Coord Rect::left() const { return _origin.x(); }
void Rect::left(Coord x) { _origin.x(x); }

Coord Rect::right() const { return _extent.x(); }
void Rect::right(Coord x) { _extent.x(x); } 

Coord Rect::top() const { return _origin.y(); }
void Rect::top(Coord y) { _origin.y(y); }

Coord Rect::bottom() const { return _extent.y(); }
void Rect::bottom(Coord y) { _extent.y(y); }

Point& Rect::origin() { return _origin; }
void Rect::origin(const Point& o) { _origin = o; }

Point& Rect::extent() { return _extent; }
void Rect::extent(const Point& e) { _extent = e; }

void Rect::moveTo(const Point& org) 
{   
    Point e(width(), height());
    origin(org);
    extent(org + e);
}
void Rect::moveBy(const Point& pt) 
{
    origin(origin() + pt);
    extent(extent() + pt);
}

bool Rect::isEmpty() const { return true; }

bool Rect::contains(const Point& p) const
{
    return (p.x() >= top() && p.x() <= bottom() && p.y() >= left() && p.y() <= right());
}

bool Rect::intersects(const Rect& other) const
{
    return (
            contains(other._origin) ||
            contains(Point(other.left(), other.bottom())) ||
            contains(Point(other.right(), other.top())) ||
            contains(other._extent) ||
            other.contains(_origin) ||
            other.contains(_extent) ||
            other.contains(Point(left(), bottom())) ||
            other.contains(Point(right(), top()))
            );
}

Rect Rect::intersect(const Rect& rect)
{
    if (intersects(rect))
        return Rect(
            Point(std::max(left(), rect.left()), std::max(top(), rect.top())),
            Point(std::min(right(), rect.right()), std::min(bottom(), rect.bottom()))
            );      
    return Rect();
}

Rect Rect::combine(const Rect& rect)
{
    Rect r = Rect(
            Point(std::min(left(), rect.left()), std::min(top(), rect.top())),
            Point(std::max(right(), rect.right()), std::max(bottom(), rect.bottom()))
            );
    return r;
}

std::string Rect::to_string() const
{
    return "[" + _origin.to_string() + ", " + _extent.to_string() + "]";
}

bool operator==(const Rect& lhs, const Rect& rhs)
{
    return (lhs._origin == rhs._origin && lhs._extent == rhs._extent); 
}

bool operator!=(const Rect& lhs, const Rect& rhs)
{
    return (lhs._origin != rhs._origin || lhs._extent != rhs._extent);
}

std::ostream& operator<<(std::ostream& out, const Rect& rect)
{
    out << rect.to_string();
    return out;
}

