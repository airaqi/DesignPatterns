#include "doctest_main.h"
#include "map_direction.h"
#include "maze_builder_standard.hpp"

TEST_CASE("MazeBuilderStandard")
{
    MazeBuilderStandard builder;

    SUBCASE("buildMaze")
    {
        builder.buildMaze();
        CHECK(builder.getMaze());
    }

    SUBCASE("buildRoom")
    {
        builder.buildMaze();
        builder.buildRoom(1);
        CHECK(builder.getMaze()->roomNo(1));
        CHECK(builder.getMaze()->roomNo(1)->getSide(North));
        CHECK(builder.getMaze()->roomNo(1)->getSide(South));
        CHECK(builder.getMaze()->roomNo(1)->getSide(East));
        CHECK(builder.getMaze()->roomNo(1)->getSide(West));
        
        builder.buildRoom(2);
        CHECK(builder.getMaze()->roomNo(2));

        builder.buildRoom();
        CHECK(builder.getMaze()->roomNo(3));
    }

    SUBCASE("buildDoor")
    {
        builder.buildMaze();
        builder.buildRoom();
        builder.buildRoom();

        builder.buildDoor(1, 2);
        // Using the commonWall implementation that lines up rooms.
        CHECK(builder.getMaze()->roomNo(1)->getSide(East)->isDoor());
        CHECK(builder.getMaze()->roomNo(2)->getSide(West)->isDoor());
    }
}
