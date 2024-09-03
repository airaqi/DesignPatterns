#include "composite_equipment.h"
#include "equipment.h"
#include "equipment_visitor.hpp"
#include "iterator.h"
#include "list.h"
#include "list_iterator.h"
#include "watt.h"
#include <sstream>


CompositeEquipment::CompositeEquipment(const char* name) 
    : Equipment(name), _children(new List<Equipment*>()) {}

CompositeEquipment::CompositeEquipment(const char* name, double price, int power) 
    : Equipment(name, price, power), _children(new List<Equipment*>()) {}

CompositeEquipment::~CompositeEquipment() 
{
    Iterator<Equipment*>* i = createIterator();
    for (i->first(); !i->is_done(); i->next())
        delete i->currentItem();
    delete _children; 
    delete i;
}

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
    return (sum + _price);
}

Currency CompositeEquipment::discountPrice(double discount) 
{
    return (netPrice() * discount);
}

std::string CompositeEquipment::to_string(std::string prefix) {
    std::stringstream sout;
    sout << "[" << name() << "(" << power().to_string() << ") : [" << get_price() << ", " << netPrice() << "], {";
    Iterator<Equipment*>* i = createIterator();

    for (i->first(); !i->is_done(); i->next())
        sout << prefix << i->currentItem()->to_string(prefix + "\t");
    sout << "}" << "]";

    delete i;
    return sout.str();
}

void CompositeEquipment::accept(EquipmentVisitor& visitor)
{
    for (ListIterator<Equipment*> i(_children); !i.is_done(); i.next() )
        i.currentItem()->accept(visitor);
    visitor.visit(this);
}
