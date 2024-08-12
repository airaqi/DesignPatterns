// make headers
#ifndef __MAP_ROOM_BOMB_H__
#define __MAP_ROOM_BOMB_H__

#include "map_room.h"

class RoomBomb : public Room
{
    public:
        RoomBomb(int);
        ~RoomBomb();

        virtual void enter() override;
        virtual void blow();
        virtual std::string to_string() override;

    private:
        bool _is_blowed;
};

#endif /* ifndef __MAP_ROOM_BOMB_H__ */
