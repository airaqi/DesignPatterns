#include "doctest_main.h"
#include "maze_factory.h"

TEST_CASE("Test MazeFactory")
{
    MazeFactory *factory = MazeFactory::instance();

    SUBCASE("makeMaze")
    {
        Maze* maze = factory->makeMaze();
        CHECK(maze);

        delete maze;
    }

    SUBCASE("makeRoom")
    {
        Room* room = factory->makeRoom(1);
        CHECK(room);
        CHECK_EQ(1, room->roomNumber());
        CHECK(room->getSide(North));
        CHECK(room->getSide(South));
        CHECK(room->getSide(East));
        CHECK(room->getSide(West));

        delete room;
    }

    SUBCASE("makeWall")
    {
        Wall* wall = factory->makeWall();
        CHECK(wall);

        delete wall;
    }

    SUBCASE("makeDoor")
    {
        Room* room1 = factory->makeRoom(1);
        Room* room2 = factory->makeRoom(2);
        Door* door = factory->makeDoor(room1, room2);

        CHECK(door);
        CHECK_EQ(room2, door->otherSideFrom(room1));
        CHECK_EQ(room1, door->otherSideFrom(room2));

        delete door;
        delete room1;
        delete room2;
    }

    factory->destroy();
}
