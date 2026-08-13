#include "btree.hpp"
#include "btree_node.hpp"
#include <optional>
#include <ostream>
#include <string>

// --------------------------------------------------
// Btree

template<Streamable T> int Btree<T>::LIMIT = 3;
template<Streamable T> int Btree<T>::INTSPAN = 0;

template<Streamable T>
Btree<T>::Btree(int initialSpan, T defaultValue, int limit) : M(limit), _index(0) , _root(Node<T>::create(initialSpan, defaultValue)), _defaultValue(defaultValue) {}

template<Streamable T>
Btree<T>::Btree(T defaultValue) : Btree(INTSPAN, defaultValue, LIMIT) {}

template<Streamable T>
Btree<T>::Btree(int initialSpan, T defaultValue) : Btree(initialSpan, defaultValue, LIMIT) {}


template<Streamable T> int           Btree<T>::getM()                { return M; }
template<Streamable T> void          Btree<T>::setM(int m)           { M = m; }
template<Streamable T> int           Btree<T>::getIndex()            { return _index; }
template<Streamable T> void          Btree<T>::setIndex(int index)   { _index = index; }
template<Streamable T> int           Btree<T>::size()                { return _root->size(); }
template<Streamable T> Node<T>::Ptr  Btree<T>::getRoot()             { return _root; }
template<Streamable T> void          Btree<T>::next()                { if (_index < _root->span()) _index++; }
template<Streamable T> void          Btree<T>::back()                { if (_index > 1) _index--; }
template<Streamable T> void          Btree<T>::seek(int index)       { setIndex(index); }
template<Streamable T> int           Btree<T>::getTotalSpan()        { return _root->span(); }

template<Streamable T> 
std::optional<T> Btree<T>::getValue(int index)
{
    if (index > getTotalSpan()) 
        return std::optional<T>();
    return _root->getValue(index);
}

template<Streamable T>
void Btree<T>::setValue(int index, int span, T value)
{
    _root->setValue(index, span, value);
}

template<Streamable T> 
void Btree<T>::insert(int index, int span)
{
    _root->insert(index, span);
}

template<Streamable T>
std::string Btree<T>::to_string(std::string prefix) 
{
    return _root->to_string(prefix);
}

template<Streamable T>
bool Btree<T>::operator==(const Btree<T>& that) const
{
    return (
        typeid(*this) == typeid(that) &&
        _index == that._index &&
        _root == that._root &&
        _defaultValue == that._defaultValue
            );
}

template<Streamable T>
bool Btree<T>::operator!=(const Btree<T>& that) const
{
    return !(*this == that);
}

template<Streamable T>
std::ostream& operator<<(std::ostream& out, Btree<T>& that)
{
    out << that.to_string();
    return out;
}




