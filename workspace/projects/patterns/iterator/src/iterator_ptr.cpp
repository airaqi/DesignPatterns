#include "iterator_ptr.hpp"


template<class Item>
IteratorPtr<Item>::IteratorPtr(Iterator<Item>* i) : _i(i) {}

template<class Item>
IteratorPtr<Item>::IteratorPtr(const IteratorPtr& it) : _i(it._i) {}

template<class Item>
IteratorPtr<Item>::~IteratorPtr()
{
    delete _i;
}

template<class Item>
IteratorPtr<Item>* IteratorPtr<Item>::operator->()
{
    return _i;
}

template<class Item>
IteratorPtr<Item>& IteratorPtr<Item>::operator*()
{
    return *_i;
}

template<class Item>
IteratorPtr<Item>& IteratorPtr<Item>::operator=(const IteratorPtr& it)
{
    _i = it._i;
    return this;
}

template<class Item>
void IteratorPtr<Item>::first()
{
    _i->first();
}

template<class Item>
void IteratorPtr<Item>::next()
{
    _i->next();
}

template<class Item>
bool IteratorPtr<Item>::is_done() const
{
    return _i->is_done();
}

template<class Item>
Item IteratorPtr<Item>::currentItem() const
{
    return _i->currentItem();
}
