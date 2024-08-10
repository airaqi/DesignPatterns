#include "glyph_decorator.h"

GlyphDecorator::GlyphDecorator(Glyph* component) : _component(component) {}

void GlyphDecorator::draw(Window *window)
{
    _component->draw(window);
}

GlyphDecorator::~GlyphDecorator() {
    delete _component;
}
