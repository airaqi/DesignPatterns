#ifndef __CABINET_H__
#define __CABINET_H__ 

#include "composite_equipment.h"

class Cabinet : public CompositeEquipment
{
    public:
        Cabinet(const char* name);
        Cabinet(const char* name, double price, int power);
        virtual ~Cabinet();

        virtual void accept(EquipmentVisitor&);
};

#endif /* ifndef __CABINET_H__ */
