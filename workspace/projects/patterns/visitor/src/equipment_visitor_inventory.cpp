#include "equipment_visitor_inventory.hpp"
#include "bus.h"
#include "card.h"
#include "chassis.h"
#include "composite_equipment.h"
#include "floppy_disk.h"
#include "leaf_equipment.h"

EquipmentInventoryVisitor::EquipmentInventoryVisitor() {}

EquipmentInventoryVisitor::~EquipmentInventoryVisitor() {}

Inventory& EquipmentInventoryVisitor::getInventory()
{
    return _inventory;
}

void EquipmentInventoryVisitor::reset()
{
    _inventory.getInventory().clear();
}

void EquipmentInventoryVisitor::visit(CompositeEquipment* equipment)
{
    _inventory.accumulate(equipment->getClassId());
}

void EquipmentInventoryVisitor::visit(LeafEquipment* equipment)
{
    _inventory.accumulate(equipment->getClassId());
}

void EquipmentInventoryVisitor::visit(Bus* equipment)
{
    _inventory.accumulate(equipment->getClassId());
}

void EquipmentInventoryVisitor::visit(Cabinet* equipment)
{
    _inventory.accumulate(equipment->getClassId());
}

void EquipmentInventoryVisitor::visit(Chassis* equipment)
{
    _inventory.accumulate(equipment->getClassId());
}

void EquipmentInventoryVisitor::visit(FloppyDisk* equipment)
{
    _inventory.accumulate(equipment->getClassId());
}


void EquipmentInventoryVisitor::visit(Card* equipment)
{
    _inventory.accumulate(equipment->getClassId());
}


