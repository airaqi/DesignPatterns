#ifndef __CARD_H__
#define __CARD_H__ 

#include "leaf_equipment.h"

class Card : public LeafEquipment
{
    public: 
        Card(const char* name) : LeafEquipment(name) {}
        Card(const char* name, double price, int power) : LeafEquipment(name, price, power) {}
        virtual ~Card() {}
};

#endif /* ifndef __CARD_H__ */
