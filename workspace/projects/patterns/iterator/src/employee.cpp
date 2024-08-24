#include "employee.h"
#include <cstring>


Employee::Employee(const char* n) 
{
    name(n);
}
Employee::~Employee() {}

const char* Employee::name() const
{
    return _name;
}

void Employee::name(const char* name) 
{
    std::strcpy(_name, name);
}

int Employee::age() const
{
    return _age;
}

void Employee::age(int a)
{
    _age = a;
}
