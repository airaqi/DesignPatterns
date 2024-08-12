#include <doctest/doctest.h>
#include <string>
#include "list_iterator.h"

TEST_CASE("Testing list iterator") {

    // Setup the list
    int size = 3;
    std::string words[] = { "Hello", "List", "Iterator" };
    List<std::string> list;

    for (int i = 0; i < size; i++)
        list.append(words[i]);

    ListIterator<std::string> iterator(&list);

    SUBCASE("first") {
        list.first();
        CHECK(iterator.currentItem() == "Hello");
    }

    SUBCASE("next") {
        iterator.next();
        CHECK(iterator.currentItem() == "List");
        iterator.next();
        CHECK(iterator.currentItem() == "Iterator");
    }
    
    SUBCASE("is_done") {
        for (int i = 0; i < list.count()-1; i++) {
            CHECK(iterator.is_done() == false);
            iterator.next();
        }
        
        iterator.next();
        CHECK(iterator.is_done() == true);
        
            

    }
}


