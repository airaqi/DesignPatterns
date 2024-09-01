#include "map_maze_factory_prototype.hpp"
#include "map_maze_game.h"
#include "map_maze_player.hpp"
#include "map_room_bomb.h"
#include "map_wall_blown.h"
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Hello, Prototype!\n";

    MazeGame game;
    MazePlayer player;

    MazePrototypeFactory simpleFactory;
    Maze *maze = game.createMaze(simpleFactory);

    player.play(maze);
    delete maze;

    MazePrototypeFactory bombedMazeFactory(new Maze, new WallBlown, new RoomBomb, new Door);
    maze = game.createMaze(bombedMazeFactory);

    player.play(maze);
    delete maze;

    return 0;
}
