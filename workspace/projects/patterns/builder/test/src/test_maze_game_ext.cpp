#include "doctest_main.h"

#include "map_direction.h"
#include "map_maze.h"
#include "maze_builder_counting.hpp"
#include "maze_builder_standard.hpp"
#include "maze_game_ext.hpp"

TEST_CASE("MazeBuilderCouting")
{
    MazeGameExt game;

    SUBCASE("createMazeStandard")
    {
        MazeBuilderStandard builder;
        game.createMaze(builder);
        Maze* maze = builder.getMaze();

        CHECK(maze->roomNo(1));
        CHECK(maze->roomNo(2));

        CHECK(maze->roomNo(1)->getSide(North));
        CHECK(maze->roomNo(1)->getSide(South));
        CHECK(maze->roomNo(1)->getSide(East));
        CHECK(maze->roomNo(1)->getSide(West));

        CHECK_EQ(false, maze->roomNo(1)->getSide(North)->isDoor());
        CHECK_EQ(false, maze->roomNo(1)->getSide(South)->isDoor());
        CHECK_EQ(true, maze->roomNo(1)->getSide(East)->isDoor());
        CHECK_EQ(false, maze->roomNo(1)->getSide(West)->isDoor());

        CHECK(maze->roomNo(2)->getSide(North));
        CHECK(maze->roomNo(2)->getSide(South));
        CHECK(maze->roomNo(2)->getSide(East));
        CHECK(maze->roomNo(2)->getSide(West));

        CHECK_EQ(false, maze->roomNo(2)->getSide(North)->isDoor());
        CHECK_EQ(false, maze->roomNo(2)->getSide(South)->isDoor());
        CHECK_EQ(false, maze->roomNo(2)->getSide(East)->isDoor());
        CHECK_EQ(true, maze->roomNo(2)->getSide(West)->isDoor());
    }

    SUBCASE("createMazeCounting")
    {
        MazeBuilderCouting builder;
        game.createMaze(builder);

        CHECK_EQ(2, builder.getRooms());
        CHECK_EQ(1, builder.getDoors());
    }

    SUBCASE("createComplexMazeStandard")
    {
        MazeBuilderStandard builder;
        game.createComplexMaze(builder, 3);
        Maze *maze = builder.getMaze();

        CHECK(maze->roomNo(1));
        CHECK(maze->roomNo(2));
        CHECK(maze->roomNo(3));

        CHECK(maze->roomNo(1)->getSide(North));
        CHECK(maze->roomNo(1)->getSide(South));
        CHECK(maze->roomNo(1)->getSide(East));
        CHECK(maze->roomNo(1)->getSide(West));

        CHECK(maze->roomNo(2)->getSide(North));
        CHECK(maze->roomNo(2)->getSide(South));
        CHECK(maze->roomNo(2)->getSide(East));
        CHECK(maze->roomNo(2)->getSide(West));

        CHECK(maze->roomNo(3)->getSide(North));
        CHECK(maze->roomNo(3)->getSide(South));
        CHECK(maze->roomNo(3)->getSide(East));
        CHECK(maze->roomNo(3)->getSide(West));

        CHECK_EQ(false, maze->roomNo(1)->getSide(North)->isDoor());
        CHECK_EQ(false, maze->roomNo(1)->getSide(South)->isDoor());
        CHECK_EQ(true, maze->roomNo(1)->getSide(East)->isDoor());
        CHECK_EQ(false, maze->roomNo(1)->getSide(West)->isDoor());

        CHECK_EQ(false, maze->roomNo(2)->getSide(North)->isDoor());
        CHECK_EQ(false, maze->roomNo(2)->getSide(South)->isDoor());
        CHECK_EQ(true, maze->roomNo(2)->getSide(East)->isDoor());
        CHECK_EQ(true, maze->roomNo(2)->getSide(West)->isDoor());

        CHECK_EQ(false, maze->roomNo(3)->getSide(North)->isDoor());
        CHECK_EQ(false, maze->roomNo(3)->getSide(South)->isDoor());
        CHECK_EQ(false, maze->roomNo(3)->getSide(East)->isDoor());
        CHECK_EQ(true, maze->roomNo(3)->getSide(West)->isDoor());
    }

    SUBCASE("createComplexMazeCounting")
    {
        MazeBuilderCouting builder;
        game.createComplexMaze(builder, 10);

        CHECK_EQ(10, builder.getRooms());
        CHECK_EQ(9, builder.getDoors());
    }


}
