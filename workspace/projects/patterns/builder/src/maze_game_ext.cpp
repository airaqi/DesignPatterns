#include "maze_game_ext.hpp"

MazeGameExt::MazeGameExt() {}
MazeGameExt::~MazeGameExt() {}

Maze* MazeGameExt::createMaze(MazeBuilder& builder)
{
    builder.buildMaze();
    builder.buildRoom(1);
    builder.buildRoom(2);
    builder.buildDoor(1, 2);
    return builder.getMaze();
}

Maze* MazeGameExt::createComplexMaze(MazeBuilder& builder, int no)
{
    builder.buildMaze();
    builder.buildRoom(1);

    for (int i = 2; i <= no; i++)
    {
        builder.buildRoom(i);
        builder.buildDoor(i - 1, i);
    }

    return builder.getMaze();
}
