#include <doctest/doctest.h>
#include <string>

#include "list.h"

TEST_CASE("Testing list class") {
    List<std::string> list;
    list.append("Hello");
    list.append("There");

    SUBCASE("includes") {
        CHECK(list.includes("Hello") == true);
    }

    SUBCASE("get") {
        CHECK(list.get(0) == "Hello");
    }

    SUBCASE("count") {
        CHECK(list.count() == 2);
    }

    SUBCASE("first") {
        CHECK(list.first() == "Hello");
    }

    SUBCASE("last") {
        CHECK(list.last() == "There");
    }

    SUBCASE("append") {
        list.append("Guys");
        CHECK(list.last() == "Guys");
        CHECK_EQ("Hello, There, Guys", list.to_string());
    }

    SUBCASE("insert") {
        list.insert("Girls", 1);
        CHECK_EQ("Girls", list.get(1));
        CHECK_EQ("Hello, Girls, There", list.to_string());
    }

    SUBCASE("prepend") {
        list.prepend("Hi");
        CHECK(list.first() == "Hi");
        CHECK_EQ("Hi, Hello, There", list.to_string());
    }

    SUBCASE("remove_at") {
        list.append("Guys");
        list.append("How");
        list.append("are");
        list.append("You");
        
        long index = list.find("How");
        CHECK(list.includes("How") == true);
        list.remove_at(index);
        CHECK(list.get(index) == "are"); 
    }
}


