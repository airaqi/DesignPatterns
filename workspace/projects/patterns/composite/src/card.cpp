#include "card.h"


Card::Card(const char* name) : LeafEquipment(name) {}
Card::Card(const char* name, double price, int power) : LeafEquipment(name, price, power) {}
Card::~Card() {}


void Card::accept(EquipmentVisitor& visitor)
{
    visitor.visit(this);
}
