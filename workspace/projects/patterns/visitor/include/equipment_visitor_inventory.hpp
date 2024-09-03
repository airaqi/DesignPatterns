#ifndef __VISITOR_EQUIPMENT_INVENTORY_H__
#define __VISITOR_EQUIPMENT_INVENTORY_H__ 

#include "cabinet.h"
#include "equipment_inventory.hpp"
#include "equipment_visitor.hpp"
#include "floppy_disk.h"

class EquipmentInventoryVisitor : public EquipmentVisitor
{
    public:
        EquipmentInventoryVisitor();
        virtual ~EquipmentInventoryVisitor();

        Inventory& getInventory();

        virtual void visit(CompositeEquipment*);
        virtual void visit(LeafEquipment*);
        virtual void visit(Bus*);
        virtual void visit(Cabinet*);
        virtual void visit(Chassis*);
        virtual void visit(Card*);
        virtual void visit(FloppyDisk*);

    private:
        Inventory _inventory;
};

#endif /* ifndef __VISITOR_EQUIPMENT_INVENTORY_H__ */
