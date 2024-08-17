#include "view_composite.h"
#include "iterator.h"
#include "list.h"
#include "list_iterator.h"

ViewComposite::ViewComposite() : _children(new List<View*>)
{
}

ViewComposite::~ViewComposite()
{
    delete _children;
}

void ViewComposite::draw(BWindow *w)
{
    Iterator<View*>* i = new ListIterator<View*>(_children);
    for (i->first(); !i->is_done(); i->next())
        i->currentItem()->draw(w);
    delete i;
}

void ViewComposite::append(View *view)
{
    _children->append(view);
}

void ViewComposite::prepend(View *view)
{
    _children->prepend(view);
}

void ViewComposite::insert(View* view, int index)
{
    _children->insert(view, index);
}

View* ViewComposite::get_child(int i)
{
    return _children->get(i);
}

