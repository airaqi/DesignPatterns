#include "glyph_composite.h"
#include "glyph.h"
#include "iterator.h"
#include "list.h"
#include "list_iterator.h"
#include "rect.h"
#include <stdexcept>

/* construct new composite
 */
GlyphComposite::GlyphComposite(Glyph* parent)
    : Glyph(parent)
    , _children(new List<Glyph*>())
{
}

/* destructor
 */
GlyphComposite::~GlyphComposite() { delete _children; }

Rect GlyphComposite::rect()
{
    Rect ret;
    Iterator<Glyph*>* i = iterator();
    for (i->first(); !i->is_done(); i->next())
        ret.combine(i->currentItem()->rect());
    return ret;
}

void GlyphComposite::rect(Rect rect)
{
    throw std::runtime_error("Composite rectangles cannot be set");
}

/* returns true for composites
 */
bool GlyphComposite::isComposite() { return true; }

/* returns false for composites
 */
bool GlyphComposite::isLeaf() { return false; }

/* append a glyph to the row end
 */
void GlyphComposite::append(Glyph* glyph)
{
    _children->append(glyph);
    glyph->parent(this);
}

/* insert a glyph in certian position.
 */
void GlyphComposite::insert(Glyph* glyph, int index)
{
    _children->insert(glyph, index);
    glyph->parent(this);
}

/* remove glyph
 */
void GlyphComposite::remove(Glyph* glyph)
{
    _children->remove(glyph);
}

long GlyphComposite::count() const
{
    return _children->count();
}

/* returns child glyph in preovided index position.
 */
Glyph* GlyphComposite::child(int index)
{
    return _children->get(index);
}

Iterator<Glyph*>* GlyphComposite::iterator()
{
    Iterator<Glyph*>* i = new ListIterator<Glyph*>(_children);
    return i;
}

bool GlyphComposite::intersects(const Point& p)
{
    bool ret = false;
    Iterator<Glyph*>* i = iterator();
    for (i->first(); !i->is_done(); i->next())
        ret = ret || i->currentItem()->intersects(p);
    return ret;
}

void GlyphComposite::draw(Window* w)
{
    Iterator<Glyph*>* i = iterator();
    for (i->first(); !i->is_done(); i->next())
        i->currentItem()->draw(w);
}

void GlyphComposite::bounds(Rect& rect)
{
    Iterator<Glyph*>* i = iterator();
    for (i->first(); !i->is_done(); i->next())
        i->currentItem()->bounds(rect);
}

bool GlyphComposite::equals(Glyph* other)
{
    bool ret = true;
    Iterator<Glyph*>* i = iterator();
    Iterator<Glyph*>* o = other->iterator();

    for (i->first(), o->first(); !(i->is_done() || o->is_done()); i->next(), o->next())
        ret = ret && i->currentItem()->equals(o->currentItem());

    return ret;
}
