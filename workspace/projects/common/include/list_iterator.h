#ifndef __LIST_ITERATOR_H__
#define __LIST_ITERATOR_H__ 

/*! \class ListIterator : public Iterra
 *  \brief Brief class description
 *
 *  Detailed description
 */
#include "iterator.h"
#include "list.h"

template<class Item>
class ListIterator : public Iterator<Item>
{
public:
    ListIterator(const List<Item>* list) : _list(list), _current(0) {}

    virtual void first() { _current = 0; }
    virtual void next() { _current++; }
    virtual bool is_done() const { return (_current >= _list->count()); }
    virtual Item currentItem() const;

private:
    const List<Item>* _list;
    long _current;
};

template<class Item>
Item ListIterator<Item>::currentItem() const
{
    if (is_done()) 
        throw std::out_of_range("Iterator out of bounds");
    return _list->get(_current);
}



template<class Item>
class NullIterator : public Iterator<Item>
{
    public:
        NullIterator() : _list(nullptr) {}

        void first() { return; }
        void next() { return; }
        bool is_done() const { return true; }
        Item currentItem() const { return Item(); }

    private:
        const List<Item>* _list;
};

#endif /* ifndef __LIST_ITERATOR_H__ */
