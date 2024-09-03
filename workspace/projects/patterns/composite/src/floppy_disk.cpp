#include "floppy_disk.h"


FloppyDisk::FloppyDisk(const char* name) : LeafEquipment(name) {}
FloppyDisk::FloppyDisk(const char* name, double price, int power) : LeafEquipment(name, price, power) {}
FloppyDisk::~FloppyDisk() {}


void FloppyDisk::accept(EquipmentVisitor& visitor)
{
    visitor.visit(this);
}
