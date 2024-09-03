#ifndef __VISITOR_EQUIPMENT_PRICING_H__
#define __VISITOR_EQUIPMENT_PRICING_H__ 

#include "composite_equipment.h"
#include "currency.h"
#include "equipment_visitor.hpp"
#include "leaf_equipment.h"

class PricingEquipmentVisitor : public EquipmentVisitor
{
    public:
        PricingEquipmentVisitor();
        virtual ~PricingEquipmentVisitor();

        Currency& getTotalPrice();

        virtual void visit(Bus*);
        virtual void visit(Cabinet*);
        virtual void visit(Chassis*);
        virtual void visit(FloppyDisk*);
        virtual void visit(Card*);
        virtual void visit(LeafEquipment*);
        virtual void visit(CompositeEquipment*);

    private:
        Currency _total;
};

#endif /* ifndef __VISITOR_EQUIPMENT_PRICING_H__ */
