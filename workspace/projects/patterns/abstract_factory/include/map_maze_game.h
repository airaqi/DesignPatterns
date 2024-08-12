#ifndef __MAP_MAZE_GAME_H__
#define __MAP_MAZE_GAME_H__ 

#include "map_maze.h"
#include "map_maze_factory_abstract.h"

class MazeGame
{
    public: 
        MazeGame();

        Maze* createMaze();
        Maze* createMaze(AbstractMazeFactory& factory);
};

#endif /* ifndef __MAP_MAZE_GAME_H__ */
