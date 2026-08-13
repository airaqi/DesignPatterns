#ifndef __GLYPH_CHARACTER_H__
#define __GLYPH_CHARACTER_H__ 

#include "glyph_context.hpp"
#include "glyph_leaf.hpp"
#include "window.hpp"
#include <memory>
#include <string>

class GlyphCharacter : public GlyphLeaf 
{
    private:
        char _character;

    public:
        GlyphCharacter(char c);
        virtual ~GlyphCharacter() {}

    public:
        using Ptr = std::shared_ptr<GlyphCharacter>;
        static Ptr create(char);

        char character();

        virtual void draw(Window&, GlyphContext&);

        virtual bool is_equal(Glyph&);
        virtual std::string to_string(std::string prefix = "");
        std::string to_string(bool print, std::string prefix = "");

};

#endif /* ifndef __GLYPH_CHARACTER_H__ */
