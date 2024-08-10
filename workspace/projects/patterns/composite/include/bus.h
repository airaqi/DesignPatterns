#ifndef __BUS_H__
#define __BUS_H__ 

#include "composite_equipment.h"

class Bus : public CompositeEquipment
{
    public:
        Bus(const char* name) : CompositeEquipment(name) {}
        Bus(const char* name, double price, int power) : CompositeEquipment(name, price, power) {}
        virtual ~Bus() {}

};
#endif /* ifndef __BUS_H__ */
