#include "card.h"


Card::Card(const char* name) : LeafEquipment(name) {}
Card::Card(const char* name, double price, int power) : LeafEquipment(name, price, power) {}
Card::~Card() {}

const std::string& Card::getClassId() const
{
    static const std::string name("Card");
    return name;
}

void Card::accept(EquipmentVisitor& visitor)
{
    visitor.visit(this);
}
