#include "list_iterator.h"
#include <stdexcept>

template<class Item>
ListIterator<Item>::ListIterator(const List<Item>* list) : _list(list), _current(0) 
{}

template<class Item>
void ListIterator<Item>::first()
{
    _current = 0;
}

template<class Item>
void ListIterator<Item>::next()
{
    _current++;
}

template<class Item>
bool ListIterator<Item>::is_done() const
{
    return _current >= _list->count();
}

template<class Item>
Item ListIterator<Item>::currentItem() const
{
    if (is_done()) 
        throw std::out_of_range("Iterator out of bounds");
    return _list->get(_current);
}


