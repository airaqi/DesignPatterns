#include "bus.h"
#include "cabinet.h"
#include "card.h"
#include "chassis.h"
#include "equipment_visitor_inventory.hpp"
#include "equipment_visitor_pricing.hpp"
#include "floppy_disk.h"
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Hello, Prototype!\n";

    Cabinet* cabinet = new Cabinet("PC Cabinet", 100, 5);
    Chassis* chassis = new Chassis("PC Chassis", 300, 5);

    cabinet->add(chassis);

    Bus* bus = new Bus("MCA Bus", 0, 10);
    bus->add(new Card("16Mbs Token Ring", 500, 50));
    bus->add(new Card("128Mb Display Card", 1500, 200));
    bus->add(new Card("USB hub", 50, 50));


    chassis->add(bus);
    chassis->add(new FloppyDisk("3.5in Flobby", 200, 10));
    chassis->add(new FloppyDisk("3.5in Flobby", 200, 10));

    std::cout << "Cabinet components is : \n" << cabinet << "\n";
    std::cout << "The net price is " << cabinet->netPrice() << "\n";

    EquipmentPricingVisitor pricingVisitor;
    cabinet->accept(pricingVisitor);

    std::cout << cabinet->name() << " " << pricingVisitor.getTotalPrice() << "\n";

    EquipmentInventoryVisitor inventoryVisitor;
    cabinet->accept(inventoryVisitor);

    std::cout << "Inventory:\n" << inventoryVisitor.getInventory() << "\n";

    delete cabinet;

    return 0;
}
