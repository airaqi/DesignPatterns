#include "equipment_visitor_pricing.hpp"
#include "bus.h"
#include "cabinet.h"
#include "card.h"
#include "chassis.h"
#include "floppy_disk.h"


EquipmentPricingVisitor::EquipmentPricingVisitor() : _total(0) {}

EquipmentPricingVisitor::~EquipmentPricingVisitor() {}


Currency& EquipmentPricingVisitor::getTotalPrice()
{
    return _total;
}

void EquipmentPricingVisitor::visit(Bus* equipment)
{
    _total += equipment->get_price();
}

void EquipmentPricingVisitor::visit(Cabinet* equipment)
{
    _total += equipment->get_price();
}

void EquipmentPricingVisitor::visit(Chassis* equipment)
{
    _total += equipment->get_price();
}

void EquipmentPricingVisitor::visit(FloppyDisk* equipment)
{
    _total += equipment->get_price();
}

void EquipmentPricingVisitor::visit(Card* equipment)
{
    _total += equipment->get_price();
}

void EquipmentPricingVisitor::visit(LeafEquipment* equipment)
{
    //_total += equipment->netPrice();
}

void EquipmentPricingVisitor::visit(CompositeEquipment* equipment)
{
    //_total += equipment->netPrice();
}
