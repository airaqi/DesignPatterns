#include "map_maze.h"
#include "map_maze_player.hpp"
#include "maze_builder_counting.hpp"
#include "maze_builder_standard.hpp"
#include "maze_game_ext.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Hello, Prototype!\n";

    Maze* maze;
    MazeGameExt game;
    MazeBuilderStandard builder;
    MazeBuilderCouting counting;
    MazePlayer player;

    game.createMaze(counting);
    std::cout 
        << "Count and play standard game: \n"
        << "rooms : " << counting.getRooms()
        << " doors : " << counting.getDoors()
        << "\n";

    game.createMaze(builder);
    maze = builder.getMaze();

    player.play(maze);

    // play complex maze
    builder.resetMaze();
    counting.reset();
    
    game.createComplexMaze(counting, 10);

    std::cout
        << "Count and play complex maze: \n"
        << "rooms : " << counting.getRooms()
        << " doors : " << counting.getDoors()
        << "\n";

    game.createComplexMaze(builder, 10);
    maze = builder.getMaze();

    player.play(maze);

    return 0;
}
