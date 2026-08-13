#include "glyph_composite.hpp"
#include "glyph.hpp"
#include <algorithm>
#include <format>
#include <numeric>
#include <string>
#include <vector>

int GlyphComposite::size() 
{ 
    return std::accumulate(_children.begin(), _children.end(), 0, 
            [](int acc,  Glyph::Ptr glyph) { return acc + glyph->size(); });
}

void GlyphComposite::add(Glyph::Ptr child) { _children.push_back(child); }
void GlyphComposite::add(int index, Glyph::Ptr child) { _children.insert(_children.begin() + index, child); }
Glyph& GlyphComposite::get(int index) 
{ 
    return *(_children.at( index)); 
}

Glyph::Ptr GlyphComposite::remove(int index) 
{
    Glyph::Ptr erased = _children.at(index);
    _children.erase(_children.begin() + index); 
    return erased;
}
std::vector<Glyph::Ptr>& GlyphComposite::children() { return _children; }

Glyph::Ptr GlyphComposite::set(int index, Glyph::Ptr child) 
{
    Glyph::Ptr replaced = _children.at(index);
    _children.insert(_children.begin() + index, child);
    return replaced;
}

bool GlyphComposite::is_composite() { return true; }

bool GlyphComposite::is_equal(Glyph& that) 
{
    // return children() == that.children();
    // GlyphComposite* other = dynamic_cast<GlyphComposite*>(&that);
    // if (other) return false;

    if (children().size() != that.children().size()) return false;
    return std::equal(children().begin(), children().end(), that.children().begin(), 
            [](Glyph::Ptr lhs, Glyph::Ptr rhs)
            {
                if (lhs == rhs) return true;
                if (!lhs | !rhs) return false;
                return *lhs == *rhs;
            });
}

std::string GlyphComposite::to_string(std::string prefix) 
{
    return std::format("{}", 
            std::accumulate(_children.begin(), _children.end(), std::string(""),
                [prefix](std::string acc, Glyph::Ptr child) { return std::format("{}{}{}", acc, (!acc.empty() ? ", " : ""), child->to_string(prefix)); }));
}
