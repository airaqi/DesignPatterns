#include "doctest_main.h"
#include "equipment_inventory.hpp"
#include <sstream>
#include <string>

TEST_CASE("Test Inventory")
{
    Inventory inventory;

    SUBCASE("accumulate")
    {
        inventory.accumulate("A");
        CHECK_EQ(1, inventory.get("A"));
        inventory.accumulate("B");
        CHECK_EQ(1, inventory.get("A"));
        CHECK_EQ(1, inventory.get("B"));
        inventory.accumulate("A");
        CHECK_EQ(2, inventory.get("A"));
        CHECK_EQ(1, inventory.get("B"));
    }

    SUBCASE("to_string")
    {
        inventory.accumulate("A");
        inventory.accumulate("B");
        inventory.accumulate("A");
        inventory.accumulate("C");
        inventory.accumulate("B");
        inventory.accumulate("A");

        std::string out = inventory.to_string();
        CHECK_NE(out.length(), out.find("A: 3\n"));
        CHECK_NE(out.length(), out.find("B: 2\n"));
        CHECK_NE(out.length(), out.find("C: 1\n"));

    }

    SUBCASE("operator<<") 
    {
        inventory.accumulate("A");
        std::stringstream sout;
        sout << inventory;
        std::string out = sout.str();
        CHECK_NE(out.length(), sout.str().find("A: 1\n"));
    }
}
