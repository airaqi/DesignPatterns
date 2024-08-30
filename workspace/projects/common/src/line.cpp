#include "line.hpp"
#include <cmath>
#include <cstdlib>
#include <ostream>
#include <sstream>


Line::Line(const Point& start, const Point& end)
    : _start(start), _end(end) {}

Line::Line(Coord x1, Coord y1, Coord x2, Coord y2)
    : _start(x1, y1), _end(x2, y2) {}

Line::~Line() {}

Point Line::start() const           { return _start; }

void Line::start(const Point& p)    { _start = p; }

Point Line::end() const             { return _end; }

void Line::end(const Point& p)      { _end = p; }

Coord Line::length() const
{
    return _start.distance(_end);
}

Coord Line::slope() const
{
    if (!(end().x() - start().x()))
        return NAN;
        //return std::numeric_limits<float>::quiet_NaN();
    return (end().y() - start().y()) / (end().x() - start().x());
}

Coord Line::y_intercept() const
{
    if (std::isnan(slope())) return NAN;
    return (start().y() - slope() * start().x());
}

Point Line::center() const
{
    return Point((start().x() + end().x()) / 2.0, (start().y() + end().y()) / 2.0);
}

bool Line::parallel(const Line& that) const
{
    return (slope() == that.slope());
}

bool Line::intersects(const Line& that) const
{
     return !parallel(that);
}

bool Line::contains(const Point& that) const
{
    return ( std::isnan(slope()) ? 
            false : 
            ((that.x() >= start().x() && 
            that.x() <= end().x()) || 
            (that.x() >= end().x() && 
             that.x() <= start().x())) && 
            that.y() == (slope() * that.x()) + y_intercept());
}

void Line::moveTo(const Point& that)
{
    Point p(that - start() + end());
    start(Point(that));
    end(p);
}

void Line::moveBy(const Point& that)
{
    start(start() + that);
    end(end() + that);
}

std::string Line::to_string() const
{
    std::stringstream out;
    out << "[Line: " << _start << " -> " << _end << "]";
    return out.str();
}

bool operator==(const Line& lhs, const Line& rhs)
{
    return (lhs.start() == rhs.start() && lhs.end() == rhs.end());
}

bool operator!=(const Line& lhs, const Line& rhs)
{
    return (lhs.start() != rhs.start() || lhs.end() != rhs.end());
}

std::ostream& operator<<(std::ostream& cout, const Line& line)
{
    cout << line.to_string();
    return cout;
}
