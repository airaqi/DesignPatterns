#ifndef __LIST_ITERATOR_REVERSE_H__
#define __LIST_ITERATOR_REVERSE_H__ 

#include "iterator.h"
#include "list.h"

template<class Item>
class ReverseListIterator : public Iterator<Item>
{
    public:
        ReverseListIterator(const List<Item>*);
        virtual ~ReverseListIterator();

        virtual void first();
        virtual void next();
        virtual bool is_done() const;
        virtual Item currentItem() const;

    private:
        const List<Item>* _list;
        int _current;
        int _size;
};

#include "list_iterator_reverse.cpp"

#endif /* ifndef __LIST_ITERATOR_REVERSE_H__ */
