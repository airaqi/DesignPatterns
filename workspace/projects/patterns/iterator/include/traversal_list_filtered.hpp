#ifndef __TRAVERSAL_LIST_FILTERED_H__
#define __TRAVERSAL_LIST_FILTERED_H__ 

#include "list.h"
#include "list_iterator.h"
template<class Item>
class FilteredListTraverser
{
    public:
        FilteredListTraverser(List<Item>* list);
        virtual ~FilteredListTraverser();

        bool traverse();

    protected:
        virtual bool processItem(const Item&) = 0;
        virtual bool testItem(const Item&) = 0;

    private:
        ListIterator<Item> _iterator;
};

#include "traversal_list_filtered.cpp"

#endif /* ifndef __TRAVERSAL_LIST_FILTERED_H__ */
