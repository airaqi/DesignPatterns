#ifndef __GLYPH_COLUMN_H__
#define __GLYPH_COLUMN_H__ 

#include "glyph_character.hpp"
#include "glyph_composite.hpp"
#include "glyph_context.hpp"
#include "window.hpp"
#include <memory>
#include <string>

class GlyphColumn : public GlyphComposite
{
    private:
        GlyphCharacter::Ptr _CR;
    public:
        GlyphColumn();
        virtual ~GlyphColumn() {}

    public:
        using Ptr = std::shared_ptr<GlyphColumn>;
        static Ptr create();

        virtual void draw(Window&, GlyphContext&);
        virtual void insert(Glyph::Ptr, GlyphContext&);
        virtual Glyph& current(GlyphContext&);

        virtual bool is_equal(Glyph&);
        virtual std::string to_string(std::string prefix = "");
};

#endif /* ifndef __GLYPH_COLUMN_H__ */
