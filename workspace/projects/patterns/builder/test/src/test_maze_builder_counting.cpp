#include "doctest_main.h"

#include "maze_builder_counting.hpp"

TEST_CASE("MazeBuilderCouting")
{
    MazeBuilderCouting builder;

    SUBCASE("buildRoom")
    {
        builder.buildRoom(1);
        CHECK_EQ(1, builder.getRooms());
        CHECK_EQ(0, builder.getDoors());

        builder.buildRoom(2);
        CHECK_EQ(2, builder.getRooms());
        CHECK_EQ(0, builder.getDoors());
    }

    SUBCASE("buildDoor")
    {
        builder.buildRoom(1);
        builder.buildRoom(2);
        builder.buildDoor(1, 2);
        CHECK_EQ(2, builder.getRooms());
        CHECK_EQ(1, builder.getDoors());

        builder.buildRoom(3);
        builder.buildDoor(2, 3);
        CHECK_EQ(3, builder.getRooms());
        CHECK_EQ(2, builder.getDoors());
    }
}
