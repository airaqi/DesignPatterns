#include "view_rectangle.h"
#include "window.h"

ViewRectangle::ViewRectangle(Rect& rect) : _rect(&rect)
{
}

ViewRectangle::~ViewRectangle()
{
}

void ViewRectangle::draw(BWindow *w)
{
    w->drawRect(_rect->origin(), _rect->extent());
}
