#include "leaf_equipment.h"
#include "equipment.h"
#include "iterator.h"
#include "list_iterator.h"
#include <sstream>
#include <string>


bool LeafEquipment::isLeaf() { return true; }

Watt LeafEquipment::power() { return _power; }

Currency LeafEquipment::netPrice() { return _price; }

Currency LeafEquipment::discountPrice(const double discount) 
{
    return netPrice() * discount;
}

void LeafEquipment::add(Equipment* equipment) {}
void LeafEquipment::remove(Equipment* equipment) {}
Iterator<Equipment*>* LeafEquipment::createIterator()
{
    return new NullIterator<Equipment*>();
}

void LeafEquipment::accept(EquipmentVisitor& visitor)
{
    visitor.visit(this);
}

std::string LeafEquipment::to_string(std::string prefix)
{
    std::stringstream sout;
    sout << "[" << name() << "(" << power().value() << "): " << netPrice().to_string() << "]";
    return sout.str();
}
