#ifndef __LIST_H__
#define __LIST_H__  

#include <stdexcept>
#include <string>

#define DEFAULT_LIST_CAPACITY 200

template <class Item>
class List
{
    public:
        List(long size = DEFAULT_LIST_CAPACITY);
        List(List&);
        ~List();
        List& operator=(const List&);

        long count() const; 
        long size() const;
        Item& get(long index) const;
        Item& first() const;
        Item& last() const;

        bool includes(const Item&) const;
        long find(const Item&) const;
        void shift_right(int index = 0);
        void shift_left(int index = 0);

        void append(const Item&);
        void insert(const Item&, int);
        void prepend(const Item&);

        void remove_at(long);
        void remove(const Item&);
        void remove_last();
        void remove_first();
        void remove_all();

        Item& top() const;
        void push(const Item&);
        Item& pop();
        std::string to_string();

    private:
        Item* _items;
        long _size;
        long _count;
};

#include "list.cpp"
#endif /* ifndef __LIST_H__ */
