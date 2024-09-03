#ifndef __BUS_H__
#define __BUS_H__ 

#include "composite_equipment.h"

class Bus : public CompositeEquipment
{
    public:
        Bus(const char* name);
        Bus(const char* name, double price, int power);
        virtual ~Bus();

        virtual void accept(EquipmentVisitor&);
};

#endif /* ifndef __BUS_H__ */
