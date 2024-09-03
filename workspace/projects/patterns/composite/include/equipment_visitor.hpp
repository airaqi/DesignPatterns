#ifndef __VISITOR_EQUIPMENT_H__
#define __VISITOR_EQUIPMENT_H__ 

class LeafEquipment;
class CompositeEquipment;
class FloppyDisk;
class Card;
class Chassis;
class Cabinet;
class Bus;

class EquipmentVisitor 
{
    public:
        virtual ~EquipmentVisitor() {}

        virtual void visit(FloppyDisk*) = 0;
        virtual void visit(Card*) = 0;
        virtual void visit(Chassis*) = 0;
        virtual void visit(Cabinet*) = 0;
        virtual void visit(Bus*) = 0;
        virtual void visit(CompositeEquipment*) = 0;
        virtual void visit(LeafEquipment*) = 0;

    protected:
        EquipmentVisitor() {}
};

#endif /* ifndef __VISITOR_EQUIPMENT_H__ */
