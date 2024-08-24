#ifndef __TRAVERSAL_LIST_H__
#define __TRAVERSAL_LIST_H__ 

#include "list.h"
#include "list_iterator.h"

template<class Item>
class ListTraverser 
{
    public:
        typedef bool (* Action)(const Item&);
        typedef bool (ListTraverser::* MemberAction)(const Item&);

        ListTraverser(List<Item>* list, Action f);
        ListTraverser(List<Item>* list);
        bool traverse();
        bool traverse(Action f);
        bool traverse(MemberAction f);

        virtual bool processItem(const Item& e);

    private:
        Action _action;
        ListIterator<Item> _iterator;
};

#include "traversal_list.cpp"

#endif /* ifndef __TRAVERSAL_LIST_H__ */
