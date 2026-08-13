#ifndef __GLYPH_COMPOSITE_H__
#define __GLYPH_COMPOSITE_H__ 

#include "glyph.hpp"
#include <vector>

class GlyphComposite : public Glyph 
{
    private:
        std::vector<Glyph::Ptr> _children;

    public:
        GlyphComposite() = default;
        virtual ~GlyphComposite() {};

        int size();
        void add(Glyph::Ptr);
        void add(int, Glyph::Ptr);
        Glyph& get(int);
        Glyph::Ptr remove(int);
        Glyph::Ptr set(int, Glyph::Ptr);

        virtual std::vector<Glyph::Ptr>& children();
        virtual bool is_composite();

        virtual bool is_equal(Glyph&);
        virtual std::string to_string(std::string prefix = "");

};

#endif /* ifndef __GLYPH_COMPOSITE_H__ */
