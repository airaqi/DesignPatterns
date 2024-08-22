#include "application.hpp"
#include "application_menu.hpp"
#include "doctest_main.h"
#include "document.hpp"
#include <cstring>
#include <iostream>

TEST_CASE("application")
{
    Application app;
    std::cout << "string copoied!\n";

    SUBCASE("addDocument") 
    {
        Document doc("test");
        app.addDocument(&doc);
        CHECK_EQ(doc, *app.getDocument(0));
        std::cout << "checked\n";
    }

    SUBCASE("menu")
    {
        Menu menu("File");
        app.menu(&menu);
        CHECK_EQ(&menu, app.menu());
    }
}
