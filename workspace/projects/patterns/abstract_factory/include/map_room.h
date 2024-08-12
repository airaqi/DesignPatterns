#ifndef __MAP_ROOM_H__
#define __MAP_ROOM_H__ 

#include "map_direction.h"
#include "map_site.h"
#include <string>

class Room : public MapSite
{
    public:
        Room(int);
        ~Room();

        MapSite* getSide(Direction) const;
        void setSide(Direction, MapSite*);
        int roomNumber();

        virtual void enter() override;
        virtual std::string to_string() override;

    private:
        MapSite* _sides[4];
        int _roomNumber;
};

#endif /* ifndef __MAP_ROOM_H__ */
