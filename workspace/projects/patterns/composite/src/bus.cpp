#include "bus.h"


Bus::Bus(const char* name) : CompositeEquipment(name) {}
Bus::Bus(const char* name, double price, int power) : CompositeEquipment(name, price, power) {}
Bus::~Bus() {}


void Bus::accept(EquipmentVisitor& visitor)
{
    for (ListIterator<Equipment*> i(_children); !i.is_done(); i.next() )
        i.currentItem()->accept(visitor);
    visitor.visit(this);
}
