#include "traversal_list.hpp"
#include <iostream>
#include <stdexcept>

template<class Item>
ListTraverser<Item>::ListTraverser(List<Item>* list) : _iterator(list), _action(nullptr) {}

template<class Item>
ListTraverser<Item>::ListTraverser(List<Item>* list, Action f) : _iterator(list), _action(f) {}

template<class Item>
bool ListTraverser<Item>::traverse()
{
    if (_action)
        return traverse(_action);
    return traverse(&ListTraverser::processItem);
}

template<class Item>
bool ListTraverser<Item>::traverse(Action f)
{
    bool result = false;

     for (_iterator.first(); !_iterator.is_done(); _iterator.next())
    {
        result = f(_iterator.currentItem());
        if (result == false)
            break;
    }
    return result;
}

template<class Item>
bool ListTraverser<Item>::traverse(MemberAction f)
{
    bool result = false;

     for (_iterator.first(); !_iterator.is_done(); _iterator.next())
    {
        result = (this->*f)(_iterator.currentItem());
        if (result == false)
            break;
    }
    return result;
}

template<class Item>
bool ListTraverser<Item>::processItem(const Item& e)
{
    return true;
}


