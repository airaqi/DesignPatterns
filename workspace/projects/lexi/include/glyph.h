#ifndef __LEXI_GLYPH_H__
#define __LEXI_GLYPH_H__

#include "iterator.h"
#include "point.h"
#include "rect.h"
#include "window.h"

class Glyph {
public:
    Glyph(Glyph* parent = nullptr);

    virtual void draw(Window*) = 0;
    virtual void bounds(Rect&) = 0;
    virtual bool intersects(const Point&) = 0;

    virtual void append(Glyph*) = 0;
    virtual void insert(Glyph*, int) = 0;
    virtual void remove(Glyph*) = 0;
    virtual long count() const = 0;
    virtual Glyph* child(int) = 0;

    virtual bool isComposite() = 0;
    virtual bool isLeaf() = 0;

    virtual Glyph* parent();
    virtual void parent(Glyph* parent);
    virtual Iterator<Glyph*>* iterator() = 0;

    virtual Rect rect() = 0;

    virtual bool equals(Glyph*) = 0;

    friend bool operator==(Glyph&, Glyph&);
    friend bool operator!=(Glyph&, Glyph&);

protected:
    virtual void rect(Rect) = 0;

private:
    Glyph* _parent;
};

#endif /* ifndef __LEXI_GLYPH_H__ */
