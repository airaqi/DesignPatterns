#ifndef __BTREE_H__
#define __BTREE_H__ 

#include <concepts>
#include <optional>
#include <ostream>
#include <string>
#pragma once

template<typename T>
concept Streamable = requires(std::ostream& out, T value) {
    { out << value } -> std::same_as<std::ostream&>;
};

template<Streamable T> class Btree;
template<Streamable T> std::ostream& operator<<(std::ostream&, Btree<T>&);
template<Streamable T> class Node;


template<Streamable T>
class Btree {

    private:
        static int      LIMIT;
        static int      INTSPAN;

        int             M;
        int             _index;
        Node<T>::Ptr    _root;
        T               _defaultValue;

    public:
        Btree(T);
        Btree(int, T);
        Btree(int, T, int);

        int getM();
        void setM(int m);
        int getIndex();
        void setIndex(int index);
        int size();
        Node<T>::Ptr getRoot();
        
        void next();
        void back();
        void seek(int index);

        int getTotalSpan();
        std::optional<T> getValue(int index);
        void setValue(int index, int span, T value);
        void insert(int index, int span);

        std::string to_string(std::string prefix = "");

        bool operator==(const Btree<T>& that) const;
        bool operator!=(const Btree<T>& that) const;

        friend std::ostream& operator<< <>(std::ostream& out, Btree<T>& that);
        
};

#include "btree.inl"



#endif /* ifndef __BTREE_H__ */
