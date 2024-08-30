#ifndef __LINE_H__
#define __LINE_H__ 

#include "coord.h"
#include "point.h"
#include <ostream>
#include <string>
class Line
{
    public:
        static const Line Zero;

        Line(const Point&, const Point&);
        Line(Coord = 0.0, Coord = 0.0, Coord = 0.0, Coord = 0.0);
        virtual ~Line();

        Point start() const;        void start(const Point&);
        Point end() const;          void end(const Point&);
        
        Coord length() const;
        Coord slope() const;
        Coord y_intercept() const;
        Point center() const;
        Point intersect(const Line&);

        bool contains(const Point&) const;
        bool intersects(const Line&) const;
        bool parallel(const Line&) const;

        void moveTo(const Point&);
        void moveBy(const Point&);

        friend bool operator==(const Line&, const Line&);
        friend bool operator!=(const Line&, const Line&);

        friend std::ostream& operator<<(std::ostream&, const Line&);
        std::string to_string() const;

    private:
        Point _start;
        Point _end;
};

#endif /* ifndef __LINE_H__ */
