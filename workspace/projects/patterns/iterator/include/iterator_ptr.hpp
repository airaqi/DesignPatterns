#ifndef __ITERATOR_PTR_H__
#define __ITERATOR_PTR_H__ 

#include "iterator.h"
template<class Item>
class IteratorPtr : public Iterator<Item>
{
    public:
        IteratorPtr(Iterator<Item>* i);
        ~IteratorPtr();

        IteratorPtr<Item>* operator->();
        IteratorPtr<Item>& operator*();

        virtual void first();
        virtual void next();
        virtual bool is_done() const;
        virtual Item currentItem() const;

    private:
        IteratorPtr(const IteratorPtr&);
        IteratorPtr<Item>& operator=(const IteratorPtr&);

    private:
        Iterator<Item>* _i;
};

#include "iterator_ptr.cpp"

#endif /* ifndef __ITERATOR_PTR_H__ */
