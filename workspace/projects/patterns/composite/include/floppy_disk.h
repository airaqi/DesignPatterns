#ifndef __FLOPPY_DISK_H__
#define __FLOPPY_DISK_H__ 

#include "leaf_equipment.h"

class FloppyDisk : public LeafEquipment
{
    public:
        FloppyDisk(const char* name) : LeafEquipment(name) {}
        FloppyDisk(const char* name, double price, int power) : LeafEquipment(name, price, power) {}
        virtual ~FloppyDisk() {}

};

#endif /* ifndef __FLOPPY_DISK_H__ */
