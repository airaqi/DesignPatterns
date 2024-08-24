#include "traversal_list_filtered.hpp"


template<class Item>
FilteredListTraverser<Item>::FilteredListTraverser(List<Item>* list) : _iterator(list) {}

template<class Item>
FilteredListTraverser<Item>::~FilteredListTraverser() {}

template<class Item>
bool FilteredListTraverser<Item>::traverse()
{
    bool result = false;
    for (_iterator.first(); !_iterator.is_done(); _iterator.next())
        if (testItem(_iterator.currentItem())) 
        {
            result = processItem(_iterator.currentItem());
            if (result == false)
                break;
        }
    return result;
}
