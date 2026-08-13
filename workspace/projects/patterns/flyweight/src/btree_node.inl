#include "btree_node.hpp"
#include <format>
#include <iostream>
#include <numeric>
#include <sstream>

template<Streamable T> int Node<T>::_nextid = 0;
template<Streamable T> int Node<T>::M = 3;
template<Streamable T> const Node<T>::Ptr Node<T>::Nil = std::make_shared<Node<T>>();


template<Streamable T>
Node<T>::Node(int id, int span, T value, bool is_leaf) : 
    _id(id), _span(span), _value(value), _defaultValue(value), _is_leaf(is_leaf), _children() { _nextid = id; }

template<Streamable T>
Node<T>::Node(int span, T value, bool is_leaf) : Node(++_nextid, span, value, is_leaf) {}

template<Streamable T>
Node<T>::Node(int span, T value) : Node(++_nextid, span, value, true) {}

template<Streamable T> 
Node<T>::Ptr Node<T>::create(int span, T value) { return std::make_shared<Node<T>>(span, value); }

template<Streamable T>
Node<T>::Ptr Node<T>::create(int span, T value, bool is_leaf) { return std::make_shared<Node<T>>(span, value, is_leaf); }


template<Streamable T>
void Node<T>::refresh() 
{
    _is_leaf = !(size() > 0); 
    _span = (size() > 0 ? 
            std::accumulate(_children.begin(), _children.end(), 0, 
                [](int sum, const Node<T>::Ptr node) { return sum + node->_span; }) : 
            _span);
}

template<Streamable T> int Node<T>::size() { return std::accumulate(_children.begin(), _children.end(), _children.size(), [](int acc, Node<T>::Ptr child) { return acc + child->size(); }); }
template<Streamable T> int Node<T>::span() { return _span; }

template<Streamable T>
void Node<T>::addChild(Node::Ptr child) 
{ 
    _children.push_back(child); 
    _span += child->_span;
    refresh();
}

template<Streamable T>
void Node<T>::addChildren(std::vector<Node<T>::Ptr>& children) 
{
    for (Node::Ptr child : children)
        addChild(child);
}

template<Streamable T>
int Node<T>::getSpan() const { return _span; }

template<Streamable T>
Node<T>::Ptr Node<T>::getChild(int index) { return _children.at(index); }

template<Streamable T>
Node<T>::Ptr Node<T>::getTail() { return _children.back(); }

template<Streamable T>
Node<T>::Ptr Node<T>::removeChild(int index) 
{ 
    if (index >= _children.size())
        throw std::out_of_range("Index out of range");
    Node<T>::Ptr removed = std::move(_children[index]);
    _children.erase(_children.begin() + index);
    return removed;
}

template<Streamable T>
std::vector<typename Node<T>::Ptr> Node<T>::removeAll()
{
    std::vector<Node<T>::Ptr> removed(_children);
    _children.clear();
    refresh();
    return removed;
}

/**
 * Get value at index 
 * @param index 
 * @return std::optional<T> value.
 */
template<Streamable T>
std::optional<T> Node<T>::getValue(int index) const
{
    return getValue(index, 0);
}

template<Streamable T>
std::optional<T> Node<T>::getValue(int index, int accumulated) const
{
    if (_is_leaf && index >= accumulated && index <= accumulated + _span)
        return _value;

    for (Node::Ptr child : _children)
    {
        if (index >= accumulated && index < accumulated + child->_span)
        {
            std::optional<T> value = child->getValue(index, accumulated);
            if (value.has_value()) return value;
        }
        accumulated += child->_span;
    }

    return std::optional<T>(T());
}

template<Streamable T>
void Node<T>::setValue(int index, int span, T value)
{
    if (_is_leaf) 
    {
        setLeafValue(index, span, value);
        return;
    }

    int accumulated = 0;
    std::vector<Node::Ptr> children;
    for (Node::Ptr child : _children)
    {
        int childStart = accumulated;
        int childEnd = accumulated + child->_span;

        int overlapStart = std::max(index, childStart);
        int overlapEnd = std::min(index + span, childEnd);

        if (overlapStart < overlapEnd)
        {
            int localIndex = overlapStart - childStart;
            int localSpan = overlapEnd - overlapStart;

            child->setValue(localIndex, localSpan, value);
            if (!child->_is_leaf)
                children.insert(children.end(), child->_children.begin(), child->_children.end());
            else
                children.push_back(child);
        } 
        else
        {
            children.push_back(child);
        }

        accumulated += child->_span;
    }

    removeAll();
    addChildren(children);
    mergeChildren();
    splitChildren();
    refresh();
}

template<Streamable T>
void Node<T>::splitChildren() 
{
    auto splitPt = _children.begin() + (_children.size() / 2);
    if (_children.size() >= (M * 2 - 1))
    {
        std::vector<Node::Ptr> left(_children.begin(), splitPt);
        std::vector<Node::Ptr> right(splitPt, _children.end());

        Node::Ptr leftNode = Node::create(0, T());
        Node::Ptr rightNode = Node::create(0, T());

        leftNode->addChildren(left);
        rightNode->addChildren(right);

        removeAll();
        std::vector<Node::Ptr> v({ leftNode, rightNode });
        addChildren(v);
    }
}

template<Streamable T>
void Node<T>::setLeafValue(int index, int span, T value) 
{
    if (_value == value)
        return;

    std::vector<Node::Ptr> segments = splitSegments(index, span, value);
    // std::cout << ">>>>>>>>>>>>>>>>" << to_string(segments) << "\n";
    // std::cout << to_string(_children) << "\n";

    if (segments.size() == 1) return;

    value = T();
    addChildren(segments);
    // std::cout << to_string(_children) << "\n";
}

template<Streamable T>
std::vector<typename Node<T>::Ptr> Node<T>::splitSegments(int index, int span, T value)
{
    std::vector<Node<T>::Ptr> segments;

    int leftSpan = index;
    int midSpan = std::min(span, _span - index);
    int rightSpan = _span - (leftSpan + midSpan);

    if (leftSpan > 0)   segments.push_back(Node::create(leftSpan, _value));
    if (midSpan > 0)    segments.push_back(Node::create(midSpan, value));
    if (rightSpan > 0)  segments.push_back(Node::create(rightSpan, _value));

    return segments;
}

template<Streamable T>
void Node<T>::mergeChildren()
{
    for (int i = 1; i < size(); i++)
    {
        Node::Ptr   lhs = _children.at(i - 1),
                    rhs = _children.at(i);
        if (lhs->_is_leaf && rhs->_is_leaf && lhs->_value == rhs->_value)
        {
            lhs->_span += rhs->_span;
            removeChild(i);
        }
    }
}

template<Streamable T>
void Node<T>::insert(int index, int span)
{
    _span += span;
    if (_is_leaf) return;

    int accumulated = 0;
    for (Node::Ptr child : _children)
    {
        if (index >= accumulated && index <= accumulated + child->_span)
        {
            if (index == accumulated + child->_span && *child != *getTail())
            {
                accumulated += child->_span;
                continue;
            }
            child->insert(index - accumulated, span);
            return;
        }
        accumulated += child->_span;
    }
}

template<Streamable T>
std::string Node<T>::to_string(std::string prefix) 
{
    std::stringstream ss;
    ss << _value;
    return std::format("{}[id: {} is_leaf: {} span: {} value: {} children: {} ]", 
            prefix, _id, _is_leaf, _span, ss.str(), children_to_string(prefix));
}

template<Streamable T>
std::string Node<T>::children_to_string(std::string prefix)
{
    auto stringize = [prefix](std::string acc, Node<T>::Ptr child) { return std::format("{}{}{}", acc, "\n", child->to_string(prefix + "  ")); };
    return std::format("[{}]", std::accumulate(_children.begin(), _children.end(), std::string(""), stringize));
}

template<Streamable T>
bool Node<T>::operator==(const Node& that) const
{
    return (typeid(this) == typeid(that) && 
            _span == that._span && 
            _value == that._value && 
            _is_leaf == that._is_leaf &&
            _children == that._children);
}

template<Streamable T>
bool Node<T>::operator!=(const Node& that) const
{
    return !(*this == that);
}

template<Streamable T>
std::ostream& operator<<(std::ostream& out, Node<T>& node) 
{
    out << node.to_string();
    return out;
}


