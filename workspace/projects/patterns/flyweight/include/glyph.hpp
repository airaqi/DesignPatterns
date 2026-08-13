#ifndef __GLPH_H__
#define __GLPH_H__ 

#include "font.hpp"
#include "glyph_context.hpp"
#include <memory>
#include <optional>
#include <ostream>
#include <string>
#include <vector>
#include "window.hpp"

class Glyph 
{
    public:
        using Ptr = std::shared_ptr<Glyph>;

         Glyph() = default;
         virtual ~Glyph() {}

    public:

        virtual void draw(Window&, GlyphContext&) = 0;

        void setFont(Font::Ptr, int, GlyphContext&);
        std::optional<Font::Ptr> getFont(GlyphContext& ctxt);

        void first(GlyphContext&);
        void next(GlyphContext&);
        void prev(GlyphContext&);
        bool is_done(GlyphContext&);

        virtual Glyph& current(GlyphContext&) = 0;
        
        virtual std::vector<Glyph::Ptr>& children() = 0;

        virtual int size() = 0;
        virtual void insert(Glyph::Ptr, GlyphContext&) = 0;
        void remove(GlyphContext&);

        virtual bool is_composite();

        virtual std::string to_string(std::string prefix="");
        bool equal(Glyph& that);
        virtual bool is_equal(Glyph& that) = 0;

        bool operator==(Glyph& that);
        bool operator!=(Glyph& that);

        friend std::ostream& operator<<(std::ostream& out, Glyph& that);
};

#endif /* ifndef __GLPH_H__ */
