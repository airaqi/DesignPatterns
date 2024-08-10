#ifndef __POLYGON_H__
#define __POLYGON_H__ 

#include "glyph_leaf.h"
#include "point.h"
#include "window.h"
class Polygon : public GlyphLeaf
{
    public:
        Polygon() {}

        virtual void draw(Window*);
        virtual bool intersects(Point&);
};

#endif /* ifndef __POLYGON_H__ */
