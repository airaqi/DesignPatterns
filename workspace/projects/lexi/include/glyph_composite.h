#ifndef __GLYPH_COMPOSITE_H__
#define __GLYPH_COMPOSITE_H__

#include "glyph.h"
#include "iterator.h"
#include "list.h"
#include "rect.h"

class GlyphComposite : virtual public Glyph {
public:
    GlyphComposite(Glyph* parent = nullptr);
    virtual ~GlyphComposite();

    virtual Rect rect();

    virtual bool isComposite();
    virtual bool isLeaf();

    virtual void append(Glyph*);
    virtual void insert(Glyph*, int);
    virtual void remove(Glyph*);
    virtual long count() const;
    virtual Glyph* child(int);

    virtual void draw(Window*);
    virtual void bounds(Rect&);
    virtual bool intersects(const Point& p);
    virtual Iterator<Glyph*>* iterator();

    virtual bool equals(Glyph*);

protected:
    virtual void rect(Rect);

private:
    List<Glyph*>* _children;
};

#endif /* ifndef __GLYPH_COMPOSITE_H__ */
