#ifndef __GLYPH_DOCUMENT_H__
#define __GLYPH_DOCUMENT_H__ 

#include "glyph_composite.hpp"
#include "glyph_context.hpp"
#include <memory>
#include <string>

class GlyphDocument : public GlyphComposite
{
    public:
        GlyphDocument();
        virtual ~GlyphDocument() {}

    public:
        using Ptr = std::shared_ptr<GlyphDocument>;

        static Ptr create();


        virtual void draw(Window&, GlyphContext&);
        virtual void insert(Glyph::Ptr, GlyphContext&);
        virtual Glyph& current(GlyphContext&);

        virtual bool is_equal(Glyph&);
        virtual std::string to_string(std::string prefix = "");

};

#endif /* ifndef __GLYPH_DOCUMENT_H__ */
