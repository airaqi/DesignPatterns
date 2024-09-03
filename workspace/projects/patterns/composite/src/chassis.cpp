#include "chassis.h"


Chassis::Chassis(const char* name) : CompositeEquipment(name) {}
Chassis::Chassis(const char* name, double price, int power) : CompositeEquipment(name, price, power) {}
Chassis::~Chassis() {}

const std::string& Chassis::getClassId() const
{
    static const std::string name("Chassis");
    return name;
}

void Chassis::accept(EquipmentVisitor& visitor)
{
    for (ListIterator<Equipment*> i(_children); !i.is_done(); i.next() )
        i.currentItem()->accept(visitor);
    visitor.visit(this);
}
