#ifndef __GLYPH_LEAF_H__
#define __GLYPH_LEAF_H__ 

#include "glyph.hpp"
#include "glyph_context.hpp"
#include <vector>

class GlyphLeaf : public Glyph
{
    private:
        std::vector<Glyph::Ptr> _empty;

    public:
        GlyphLeaf() = default;
        virtual ~GlyphLeaf() {}

    public:
        int size();
        void insert(Glyph::Ptr, GlyphContext&);
        virtual Glyph& current(GlyphContext&);
        virtual std::vector<Glyph::Ptr>& children();
};

#endif /* ifndef __GLYPH_LEAF_H__ */
