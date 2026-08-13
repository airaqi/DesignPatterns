#ifndef __GLYPH_ROW_H__
#define __GLYPH_ROW_H__ 

#include "glyph_composite.hpp"
#include "glyph_context.hpp"
#include "window.hpp"
#include <memory>

class GlyphRow : public GlyphComposite
{
    public:
        GlyphRow() = default;
        virtual ~GlyphRow() {}

    public:
        using Ptr = std::shared_ptr<GlyphRow>;
        static Ptr create();

        void draw(Window&, GlyphContext&);
        void insert(Glyph::Ptr, GlyphContext&);
        Glyph& current(GlyphContext&);

        virtual bool is_equal(Glyph&);
        virtual std::string to_string(std::string prefix = "");
};

#endif /* ifndef __GLYPH_ROW_H__ */
