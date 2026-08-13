#ifndef __BTREE_NODE_H__
#define __BTREE_NODE_H__

#include "btree.hpp"
#pragma once

#include <memory>
#include <ostream>
#include <optional>
#include <string>
#include <vector>
#include <iostream>


template<Streamable T> class Node;
template<Streamable T> std::ostream& operator<<(std::ostream&, Node<T>&);

template<Streamable T>
class Node {
    public:
        using Ptr = std::shared_ptr<Node<T>>;

    private:
        static int          _nextid;
        static int          M;

        int                 _id;
        int                 _span;
        T                   _defaultValue;
        T                   _value;
        bool                _is_leaf;
        std::vector<Ptr>    _children;

    public:
        static const Ptr Nil;

        static Ptr create(int, T);
        static Ptr create(int, T, bool);

    public:
        Node(int, int, T, bool);
        Node(int, T);
        Node(int, T, bool);

        void refresh();
        int size();

        int span();

        void addChild(Node<T>::Ptr);
        void addChildren(std::vector<Node<T>::Ptr>&);
        int getSpan() const;
        Ptr getChild(int);
        Ptr getTail();
        Ptr removeChild(int);
        std::vector<Ptr> removeAll();

        std::optional<T> getValue(int) const;
        std::optional<T> getValue(int, int) const;
        void setValue(int, int, T);
        void insert(int, int);

        std::string to_string(std::string prefix = "");
        std::string children_to_string(std::string prefix = "");

        bool operator==(const Node& that) const;
        bool operator!=(const Node& that) const;

        friend std::ostream& operator<< <>(std::ostream&, Node<T>& that);

    private:
        void setLeafValue(int, int, T);
        std::vector<Ptr> splitSegments(int, int, T);
        void mergeChildren();
        void splitChildren();
};

#include "btree_node.inl"



#endif /* ifndef __BTREE_NODE_H__ */
