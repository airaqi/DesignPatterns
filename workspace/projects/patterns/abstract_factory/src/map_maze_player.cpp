#include "map_maze_player.hpp"
#include "map_door.h"
#include <iostream>


void MazePlayer::play(Maze* maze, const char *title)
{
    if (title)
        std::cout << "Game: " << title << " start ... \n";

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
