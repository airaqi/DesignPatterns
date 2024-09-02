#include <iostream>
#include "bus.h"
#include "cabinet.h"
#include "card.h"
#include "chassis.h"
#include "floppy_disk.h"
#include "list.h"

int main(int argc, char *argv[])
{
    std::cout << "Hello Composite Pattern\n";

    List<std::string> list;
    list.append("Hello");
    list.append("There");
    std::cout << list.to_string() << "\n";


    Cabinet* cabinet = new Cabinet("PC Cabinet", 100, 5);
    Chassis* chassis = new Chassis("PC Chassis", 300, 5);

    cabinet->add(chassis);

    Bus* bus = new Bus("MCA Bus", 0, 10);
    bus->add(new Card("16Mbs Token Ring", 500, 50));

    chassis->add(bus);
    chassis->add(new FloppyDisk("3.5in Flobby", 200, 10));

    std::cout << "Cabinet components is : \n" << cabinet << "\n";
    std::cout << "The net price is " << chassis->netPrice().to_string() << "\n";
    std::cout << "The discounted price is " << chassis->discountPrice(0.9).to_string() << "\n";
    std::cout << "The total power is " << chassis->power().value() << "\n";

    delete cabinet;

    return 0;
}
