#include "bus.h"
#include "cabinet.h"
#include "card.h"
#include "chassis.h"
#include "currency.h"
#include "doctest_main.h"
#include "equipment_visitor_pricing.hpp"


TEST_CASE("Test EquipmentPricingVisitor")
{
    
    SUBCASE("visitCabinet")
    {
        EquipmentPricingVisitor visitor;
        Cabinet cabinet("Cabinet", 100, 10);

        cabinet.accept(visitor);
        
        CHECK_EQ(Currency(100), visitor.getTotalPrice());
        cabinet.add(new Chassis("Chassis", 100, 10));

        visitor.reset();
        cabinet.accept(visitor);
        CHECK_EQ(Currency(200), visitor.getTotalPrice());
        cabinet.add(new Bus("Bus", 100, 10));

        visitor.reset();
        cabinet.accept(visitor);
        CHECK_EQ(Currency(300), visitor.getTotalPrice());

    }

     SUBCASE("visitBus")
    {
        EquipmentPricingVisitor visitor;
        Bus bus("Bus", 100, 10);

        bus.accept(visitor);
        
        CHECK_EQ(Currency(100), visitor.getTotalPrice());
        bus.add(new Card("Card1", 100, 10));

        visitor.reset();
        bus.accept(visitor);
        CHECK_EQ(Currency(200), visitor.getTotalPrice());
        bus.add(new Card("Card2", 100, 10));

        visitor.reset();
        bus.accept(visitor);
        CHECK_EQ(Currency(300), visitor.getTotalPrice());

    }

     SUBCASE("visit Card")
     {
         EquipmentPricingVisitor visitor;
         Card card("Card", 100, 5);

         card.accept(visitor);
         CHECK_EQ(Currency(100), visitor.getTotalPrice());
     }

   
}
