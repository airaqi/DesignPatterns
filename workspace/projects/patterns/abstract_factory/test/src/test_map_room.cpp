#include "doctest_main.h"

#include "map_direction.h"
#include "map_room.h"
#include "map_wall.h"

TEST_CASE("Test Room")
{
    SUBCASE("Constructor")
    {
        Room room(1);
        CHECK_EQ(1, room.roomNumber());
    }

    SUBCASE("Clone")
    {
        Room room(1);
        Room* clone = room.clone();
        CHECK_EQ(1, clone->roomNumber());
        CHECK_NE(&room, clone);
        delete clone;
    }

    SUBCASE("Initialize")
    {
        Room room;
        Room *clone = room.clone();
        clone->initialize(2);
        CHECK_EQ(2, clone->roomNumber());
        delete clone;
    }

    SUBCASE("GetSide")
    {
        Room room(1);
        CHECK_EQ(nullptr, room.getSide(North));
        CHECK_EQ(nullptr, room.getSide(South));
        CHECK_EQ(nullptr, room.getSide(East));
        CHECK_EQ(nullptr, room.getSide(West));
    }

    SUBCASE("SetSide")
    {
        Room room(1);
        room.setSide(North, new Wall);
        room.setSide(South, new Wall);
        room.setSide(East, new Wall);
        room.setSide(West, new Wall);
        CHECK(room.getSide(North));
        CHECK(room.getSide(South));
        CHECK(room.getSide(East));
        CHECK(room.getSide(West));
    }


    SUBCASE("ToString")
    {
        Room room(1);
        room.setSide(North, new Wall);
        room.setSide(South, new Wall);
        room.setSide(East, new Wall);
        room.setSide(West, new Wall);
       
        CHECK_NOTHROW(room.to_string());
    }
}
