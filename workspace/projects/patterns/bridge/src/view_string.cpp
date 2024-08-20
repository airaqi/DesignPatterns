#include "view_string.h"
#include "window.h"


ViewString::ViewString(const char* value, Point& location) 
    : _value(value), _location(&location) {}

ViewString::~ViewString()
{
}

void ViewString::draw(BWindow *w)
{
    w->drawText(_value, *_location);
}
