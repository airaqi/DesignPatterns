#include "equipment_visitor_pricing.hpp"
#include "bus.h"
#include "cabinet.h"
#include "card.h"
#include "chassis.h"
#include "floppy_disk.h"


PricingEquipmentVisitor::PricingEquipmentVisitor() : _total(0) {}

PricingEquipmentVisitor::~PricingEquipmentVisitor() {}


Currency& PricingEquipmentVisitor::getTotalPrice()
{
    return _total;
}

void PricingEquipmentVisitor::visit(Bus* equipment)
{
    _total += equipment->get_price();
}

void PricingEquipmentVisitor::visit(Cabinet* equipment)
{
    _total += equipment->get_price();
}

void PricingEquipmentVisitor::visit(Chassis* equipment)
{
    _total += equipment->get_price();
}

void PricingEquipmentVisitor::visit(FloppyDisk* equipment)
{
    _total += equipment->get_price();
}

void PricingEquipmentVisitor::visit(Card* equipment)
{
    _total += equipment->get_price();
}

void PricingEquipmentVisitor::visit(LeafEquipment* equipment)
{
    //_total += equipment->netPrice();
}

void PricingEquipmentVisitor::visit(CompositeEquipment* equipment)
{
    //_total += equipment->netPrice();
}
