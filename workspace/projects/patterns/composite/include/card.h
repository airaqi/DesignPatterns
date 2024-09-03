#ifndef __CARD_H__
#define __CARD_H__ 

#include "leaf_equipment.h"

class Card : public LeafEquipment
{
    public: 
        Card(const char* name);
        Card(const char* name, double price, int power);
        virtual ~Card();

        virtual const std::string& getClassId() const;

        virtual void accept(EquipmentVisitor&);
};

#endif /* ifndef __CARD_H__ */
