#include "list_iterator_reverse.h"
#include <stdexcept>

template<class Item>
ReverseListIterator<Item>::ReverseListIterator(const List<Item>* list) :
    _list(list), _current(list->count() - 1) , _size(list->count() - 1){}

template<class Item>
ReverseListIterator<Item>::~ReverseListIterator() {}

template<class Item>
void ReverseListIterator<Item>::first()
{
    _current = _size;
}

template<class Item>
void ReverseListIterator<Item>::next()
{
    --_current;
}

template<class Item>
bool ReverseListIterator<Item>::is_done() const
{
    return _current < 0;
}

template<class Item>
Item ReverseListIterator<Item>::currentItem() const
{
    if (is_done())
        throw std::out_of_range("Reverse iterator out of bounds");
    return _list->get(_current);
}
