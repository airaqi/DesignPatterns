#ifndef __GLYPH_LEAF_H__
#define __GLYPH_LEAF_H__ 

#include "glyph.h"
#include "iterator.h"
#include "rect.h"

#define ERR_LEAF_CHILDREN "Leaf glyphs cannot have children glyphs"

class GlyphLeaf : virtual public Glyph
{
    public:
        GlyphLeaf(Glyph* parent = nullptr);
        
        virtual bool isLeaf();
        virtual bool isComposite();

        virtual void bounds(Rect&);
        virtual void append(Glyph*);
        virtual void insert(Glyph*,int);
        virtual void remove(Glyph*);
        virtual long count() const;
        virtual Glyph* child(int);

        virtual bool intersects(const Point& rect);
        virtual Iterator<Glyph*>* iterator();

        virtual bool equals(Glyph*);

        virtual Rect rect();

    protected:
         virtual void rect(Rect rect);

    private:
        Rect _rect;
};

#endif /* ifndef __GLYPH_LEAF_H__ */
