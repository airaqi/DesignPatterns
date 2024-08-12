#ifndef __MAP_MAZE_H__
#define __MAP_MAZE_H__ 

#include "map_room.h"
#include <ostream>
#include <string>
#include <unordered_map>

class Maze
{
    public:
        Maze();
        virtual ~Maze();

        void addRoom(Room*);
        void addStart(Room*);
        void addTarget(Room*);
        Room* roomNo(int) const;
        bool isTarget(Room*) const;

        int start() const { return _start; }
        int target() const {return _target; }

        virtual std::string to_string() const;
        friend std::ostream& operator<<(std::ostream&, Maze*);

    private:
        std::unordered_map<int, Room*> _rooms;
        int _start;
        int _target;
        int _current;
};

#endif /* ifndef __MAP_MAZE_H__ */
