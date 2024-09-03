#include "cabinet.h"


Cabinet::Cabinet(const char* name) : CompositeEquipment(name) {}
Cabinet::Cabinet(const char* name, double price, int power) : CompositeEquipment(name, price, power) {}
Cabinet::~Cabinet() {}

const std::string& Cabinet::getClassId() const
{
    static const std::string name("Cabinet");
    return name;
}

void Cabinet::accept(EquipmentVisitor& visitor)
{
    for (ListIterator<Equipment*> i(_children); !i.is_done(); i.next() )
        i.currentItem()->accept(visitor);
    visitor.visit(this);
}
