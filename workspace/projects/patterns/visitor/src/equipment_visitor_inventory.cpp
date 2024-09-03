#include "equipment_visitor_inventory.hpp"
#include "composite_equipment.h"
#include "leaf_equipment.h"

EquipmentInventoryVisitor::EquipmentInventoryVisitor() {}

EquipmentInventoryVisitor::~EquipmentInventoryVisitor() {}

Inventory& EquipmentInventoryVisitor::getInventory()
{
    return _inventory;
}

void EquipmentInventoryVisitor::visit(CompositeEquipment* equipment)
{
    _inventory.accumulate(typeid(equipment).name());
}

void EquipmentInventoryVisitor::visit(LeafEquipment* equipment)
{
    _inventory.accumulate(typeid(equipment).name());
}

void EquipmentInventoryVisitor::visit(Bus* equipment)
{
    _inventory.accumulate(typeid(equipment).name());
}

void EquipmentInventoryVisitor::visit(Cabinet* equipment)
{
    _inventory.accumulate(typeid(equipment).name());
}

void EquipmentInventoryVisitor::visit(Chassis* equipment)
{
    _inventory.accumulate(typeid(equipment).name());
}

void EquipmentInventoryVisitor::visit(FloppyDisk* equipment)
{
    _inventory.accumulate(typeid(equipment).name());
}


void EquipmentInventoryVisitor::visit(Card* equipment)
{
    _inventory.accumulate(typeid(equipment).name());
}


