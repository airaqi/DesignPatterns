#include <sstream>

/* Initialize the list.
 * the size parameter is a hint for the initial number of elements.
 */
template<class Item>
List<Item>::List(long size) : _items(new Item[size]), _count(0), _size(size) {}

/* Overrides the default copy constructor so that member data are
 * initilized properly.
 */
template<class Item>
List<Item>::List(List& other) 
{
    _size = other._size;
    _count = other._count;

    _items = new Item[_size];

    for (long i = 0; i < _count; i++)
        _items[i] = other._items[i];
}

/* Frees the list's internal data structures but not the elements in 
 * the list. The class is not designed for subclassing; therefore the 
 * destructor is not virtual.
 */
template<class Item>
List<Item>::~List() { delete[] _items; }

/* implements the assignment operator to assign member data properly.
 */
template<class Item>
List<Item>& List<Item>::operator=(const List& other) 
{
    if (this != &other)
    {
        // Clear the current list
        remove_all();

        // Allocate memory for the new list
        _size = other.size;
        _count = other._count;
        _items = new Item[_size];

        // copy elements from the other list to this list
        for (long i = 0; i < _count; ++i)
            _items[i] = other._items[i];
    }
    
    return *this;
}

/* Returns the number of objects in the list.
 */
template<class Item>
long List<Item>::count() const 
{
    return _count;
}

template<class Item>
long List<Item>::size() const
{
    return _size;
}

/* Returns the object at the given index.
 */
template<class Item>
Item& List<Item>::get(long index) const 
{
    if (index <= _count)
        return _items[index];
    else 
        throw std::out_of_range("Index out of range in List::get");
}

/* Returns first object in list.
 */
template<class Item>
Item& List<Item>::first() const { return get(0); }

/* Returns the last element in the list.
 */
template<class Item>
Item& List<Item>::last() const { return get(count() - 1); }

/* Check whether item exists in the list.
 */
template<class Item>
bool List<Item>::includes(const Item& item) const
{
    if (find(item) != -1)
        return true;
    return false;

}

template<class Item>
long List<Item>::find(const Item& item) const
{
    for (long i = 0; i < _count; ++i)
        if (_items[i] == item)
            return i;
    return -1;
}

/* shifts all items one cell to the right 
 * starting from index.
 */
template<class Item>
void List<Item>::shift_right(int index)
{
    if (count() < size()) 
    {
        for(long i = count(); i >= index; --i)
            _items[i+1] = _items[i];
        _count++;
    }
}

/* shifts items one cell to the left, 
 * and removing item at index.
 */
template<class Item>
void List<Item>::shift_left(int index)
{
    if (count() < size())
    {
        for (long i = index; i < count() - 1; i++)
            _items[i] = _items[i+1];
        _count--;
    }
}

/* Adds item at the list tail.
 */
template<class Item>
void List<Item>::append(const Item& item)
{
    if (_count <= _size) 
    {
        _items[_count] = item;
        _count++;
    }
}

template<class Item>
void List<Item>::insert(const Item& item, int index)
{
    if (count() <= _size)
    {
        shift_right(index);
        _items[index] = item;
    }
}

/* Adds item at the list head.
 */
template<class Item>
void List<Item>::prepend(const Item& item)
{
    if (_count <= _size) 
    {
        shift_right();
        _items[0] = item;
    }
}

/* Remove item located at index position.
 */
template<class Item>
void List<Item>::remove_at(long index)
{
    if (index < 0 || index >= count())
        throw std::range_error("Range out of bounds");

    shift_left(index);
}

/* Removes the given item from the list. This operation requires that the type 
 * of elements supports == operator for comparison.
 */
template<class Item>
void List<Item>::remove(const Item& item)
{
    for (long i = 0; i < count(); i++)
        if (_items[i] == item)
            remove_at(i);
}

/* Removes first element of the list
 */
template<class Item>
void List<Item>::remove_first()
{
    remove_at(0);
}

/* Removes the last element of the list.
 */
template<class Item>
void List<Item>::remove_last()
{
    remove_at(count() - 1);
}

/* Remove all elements
 */
template<class Item>
void List<Item>::remove_all()
{
    _count = 0;
}

/* Returns the top element 
 */
template<class Item>
Item& List<Item>::top() const
{
    return last();
}

/* Push element onto the stack
 */
template<class Item>
void List<Item>::push(const Item& item)
{
    append(item);
}

/* Pops the top element of the stack.
 */
template<class Item>
Item& List<Item>::pop() 
{
    Item& top = last();
    remove_last();
    return top;
}

template<class Item>
std::string List<Item>::to_string()
{
    std::stringstream ss;
    for (int i = 0; i < count(); i++) {
        if (i > 0) ss << ", ";
        ss << _items[i];
    }
    return ss.str();
}

