#include "doctest_main.h"
#include "map_door.h"
#include "map_room.h"

TEST_CASE("Test Door")
{
    Room room1(1);
    Room room2(2);
    Door door(&room1, &room2);

    SUBCASE("constructor")
    {
        CHECK(&door);
    }

    SUBCASE("clone")
    {
        Door *clone = door.clone();
        CHECK_NE(clone, &door);
        delete clone;
    }

    SUBCASE("initialize")
    {
        Door *clone = door.clone();
        clone->initialize(&room1, &room2);
        CHECK(clone);
        CHECK_NE(clone, &door);
        CHECK_EQ(&room2, clone->otherSideFrom(&room1));

        delete clone;
    }

    SUBCASE("otherSideFrom")
    {
        CHECK_EQ(&room2, door.otherSideFrom(&room1));
        CHECK_EQ(&room1, door.otherSideFrom(&room2));
    }

    SUBCASE("isDoor")
    {
        CHECK_EQ(true, door.isDoor());
    }
}
