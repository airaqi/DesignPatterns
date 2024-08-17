#ifndef __ITERATOR_H__
#define __ITERATOR_H__ 

template<class Item>
class Iterator 
{
    public:
        virtual ~Iterator() {}

        virtual void first() = 0;
        virtual void next() = 0;
        virtual bool is_done() const = 0;
        virtual Item currentItem() const = 0;

    protected:
        Iterator() {}
};

#endif /* ifndef __ITERATOR_H__ */
