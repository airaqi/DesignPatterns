#include "composite_equipment.h"
#include "equipment.h"
#include "iterator.h"
#include "list.h"
#include "list_iterator.h"
#include "watt.h"
#include <sstream>

CompositeEquipment::~CompositeEquipment() { delete[] _children; }

void CompositeEquipment::add(Equipment* child) 
{
    _children->append(child);
}

void CompositeEquipment::remove(Equipment* child)
{
    _children->remove(child);
}

Iterator<Equipment*>* CompositeEquipment::createIterator()
{
    return new ListIterator<Equipment*>(_children);
}

Watt CompositeEquipment::power() 
{
    Watt sum;
    Iterator<Equipment*>* i = createIterator();
    for (i->first(); !i->is_done(); i->next())
        sum = sum + i->currentItem()->power();
    delete i;
    return sum;
}

Currency CompositeEquipment::netPrice() 
{
    Currency sum;
    Iterator<Equipment*>* i = createIterator();
    for (i->first(); !i->is_done(); i->next())
        sum = sum + i->currentItem()->netPrice();
    delete i;
    return sum;
}

Currency CompositeEquipment::discountPrice(double discount) 
{
    return (netPrice() * discount);
}

std::string CompositeEquipment::to_string() {
    std::stringstream sout;
    sout << "[" << name() << "(" << power().to_string() << ") : " << netPrice().to_string() << ", {";
    Iterator<Equipment*>* i = createIterator();

    for (i->first(); !i->is_done(); i->next())
        sout << i->currentItem()->to_string();
    sout << "}" << "]";

    return sout.str();
}
