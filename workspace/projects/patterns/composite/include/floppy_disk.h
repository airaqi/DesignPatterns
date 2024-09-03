#ifndef __FLOPPY_DISK_H__
#define __FLOPPY_DISK_H__ 

#include "leaf_equipment.h"

class FloppyDisk : public LeafEquipment
{
    public:
        FloppyDisk(const char* name);
        FloppyDisk(const char* name, double price, int power);
        virtual ~FloppyDisk();

        virtual const std::string& getClassId() const;

        virtual void accept(EquipmentVisitor&);
};

#endif /* ifndef __FLOPPY_DISK_H__ */
