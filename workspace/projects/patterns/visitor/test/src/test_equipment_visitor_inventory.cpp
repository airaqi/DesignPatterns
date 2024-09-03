#include "cabinet.h"
#include "card.h"
#include "chassis.h"
#include "doctest_main.h"
#include "equipment_visitor_inventory.hpp"
#include <iostream>

TEST_CASE("Test EquipementInventoryVisitor")
{
    SUBCASE("visitCabinet")
    {
        EquipmentInventoryVisitor visitor;
        Cabinet cabinet("Cabinet", 100, 10);

        cabinet.accept(visitor);
        std::cout << visitor.getInventory() << "\n";
        std::cout << typeid(cabinet).name() << "\n";
        CHECK_EQ(1, visitor.getInventory().get(cabinet.getClassId()));

        Chassis *chassis = new Chassis("Chassis", 200, 20);
        cabinet.add(chassis);
        visitor.reset();
        cabinet.accept(visitor);
        CHECK_EQ(1, visitor.getInventory().get(cabinet.getClassId()));
        CHECK_EQ(1, visitor.getInventory().get(chassis->getClassId()));
    }

    SUBCASE("visitCard")
    {
        EquipmentInventoryVisitor visitor;
        Card card("Card", 100, 10);
    
        card.accept(visitor);
        CHECK_EQ(1, visitor.getInventory().get(card.getClassId()));

    }
}
