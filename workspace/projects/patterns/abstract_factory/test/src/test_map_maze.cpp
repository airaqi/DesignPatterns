#include "doctest_main.h"
#include "map_maze.h"

TEST_CASE("Test Maze")
{
    Maze maze;

    SUBCASE("Test add room")
    {
        Room *room = new Room(1);
        maze.addRoom(room);
        CHECK_EQ(room, maze.roomNo(1));
        //delete room;
    }

    SUBCASE("Test add target")
    {
        Room *room = new Room(1);
        maze.addTarget(room);
        CHECK(maze.isTarget(room));
        //delete room;
    }

    SUBCASE("Test add start")
    {
        Room *room = new Room(1);
        maze.addStart(room);
        CHECK(maze.start());
        //delete room;
    }

    SUBCASE("Test to_string")
    {
        CHECK_EQ("[Maze : start: 0 end: 0\n\t]", maze.to_string());
    }

    SUBCASE("Test clone")
    {
        Maze *clone = maze.clone();
        CHECK(clone);
        CHECK_NE(&maze, clone);
        delete clone;
    }

    
}
