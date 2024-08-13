
#include "map_direction.h"
#include "map_door.h"
#include "map_maze_factory_abstract.h"
#include "map_maze_factory_magic.h"
#include "map_maze_game.h"
#include "map_site.h"
#include "maze_factory.h"
#include <iostream>
#include <string>

void play(Maze* maze)
{
    std::string directions[] = { "North", "South", "East", "West" };
    Room* room = maze->roomNo(maze->start());
    MapSite* last_door = nullptr;

    std::cout << "play " << maze << "\n";
    room->enter();

    while (!maze->isTarget(room)) {
        //std::cout << *room << "\n";
        for (Direction dir(North); dir <= West; dir = static_cast<Direction>(dir + 1)) {
            std::cout << "going " << directions[dir] << " --> ";
            MapSite* site = room->getSide(dir);
            site->enter();
            if (site->isDoor()) {
                room = dynamic_cast<Door*>(site)->otherSideFrom(room);
                if (site != last_door) {
                    last_door = site;
                    room->enter();
                    break;
                }
            }
        }
    }

    std::cout << "played " << maze << "\n";
}

int main(int argc, char* argv[])
{
    MazeGame game;

    Maze* maze = game.createMaze();
    play(maze);
    delete maze;

    std::cout << "\n\n";

    AbstractMazeFactory* factory = MazeFactory::instance();
    Maze* maze2 = game.createMaze(*factory);

    play(maze2);
    delete maze2;
    delete factory;

    std::cout << "\n\n";

    factory = BombMazeFactory::instance();
    Maze* maze3 = game.createMaze(*factory);

    play(maze3);
    delete factory;
    delete maze3;
    return 0;
}
