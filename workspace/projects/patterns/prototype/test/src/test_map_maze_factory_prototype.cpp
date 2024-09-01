#include "doctest_main.h"
#include "map_direction.h"
#include "map_door.h"
#include "map_maze.h"
#include "map_maze_factory_prototype.hpp"
#include "map_room.h"
#include "map_wall.h"

TEST_CASE("Test MazePrototypeFactory")
{
    Maze *pMaze = new Maze;
    Wall *pWall = new Wall;
    Room *pRoom = new Room;
    Door *pDoor = new Door;

    MazePrototypeFactory simpleFactory(pMaze, pWall, pRoom, pDoor);

    SUBCASE("makeMaze")
    {
        Maze *maze = simpleFactory.makeMaze();
        CHECK(maze);
        CHECK_NE(pMaze, maze);

        delete maze;
    }

    SUBCASE("makeRoom")
    {
        Room *room = simpleFactory.makeRoom(1);
        CHECK(room);
        CHECK_NE(pRoom, room);
        CHECK_EQ(1, room->roomNumber());
        CHECK(room->getSide(North));
        CHECK(room->getSide(South));
        CHECK(room->getSide(East));
        CHECK(room->getSide(West));

        delete room;
    }

    SUBCASE("makeWall")
    {
        Wall *wall = simpleFactory.makeWall();
        CHECK(wall);
        CHECK_NE(pWall, wall);

        delete wall;
    }

    SUBCASE("makeDoor")
    {
        Room *room1 = simpleFactory.makeRoom(1);
        Room *room2 = simpleFactory.makeRoom(2);
        Door *door = simpleFactory.makeDoor(room1, room2);

        CHECK(door);
        CHECK_NE(pDoor, door);
        CHECK_EQ(room2, door->otherSideFrom(room1));
        CHECK_EQ(room1, door->otherSideFrom(room2));

        delete door;
        delete room1;
        delete room2;
    }
}
