#ifndef __MAP_DOOR_H__
#define __MAP_DOOR_H__ 

#include "map_room.h"
#include "map_site.h"

class Door : public MapSite
{
    public:
        Door(Room* = 0, Room* = 0, bool = true);
        virtual ~Door();

        void enter() override;
        Room* otherSideFrom(Room*);
        bool isDoor() const override;
        virtual std::string to_string() override;
        virtual void mark() override;
        virtual bool marked() override;


    private:
        Room* _room1;
        Room* _room2;
        bool _isOpen;
        bool _isMarked;
};

#endif /* ifndef __MAP_DOOR_H__ */
