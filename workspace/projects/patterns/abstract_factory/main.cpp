
#include "map_maze_factory_abstract.h"
#include "map_maze_factory_magic.h"
#include "map_maze_game.h"
#include "map_maze_player.hpp"
#include "maze_factory.h"
#include <iostream>

int main(int argc, char* argv[])
{
    MazeGame game;
    MazePlayer player;

    Maze* maze = game.createMaze();
    player.play(maze);
    delete maze;

    std::cout << "\n\n";

    AbstractMazeFactory* factory = MazeFactory::instance();
    Maze* maze2 = game.createMaze(*factory);

    player.play(maze2);
    delete maze2;
    delete factory;

    std::cout << "\n\n";

    factory = BombMazeFactory::instance();
    Maze* maze3 = game.createMaze(*factory);

    player.play(maze3);
    delete factory;
    delete maze3;
    return 0;
}
