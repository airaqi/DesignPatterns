#include "watt.h"
#include <stdexcept>
#include <string>

bool operator==(Watt w1, Watt w2) 
{
    return (w1.value() == w2.value());
}

Watt operator+(Watt w1, Watt w2) 
{
    return Watt(w1.value() + w2.value());
}

Watt operator-(Watt w1, Watt w2) 
{
    return Watt(w1.value() - w2.value());
}

Watt operator*(Watt w, double d) 
{
    return Watt(w.value() * d);
}

Watt operator/(Watt w, double d) 
{
    return (d != 0 ? Watt(w.value() / d) : throw std::runtime_error("Division by zero error."));
}

std::string Watt::to_string()
{
    return "W" + std::to_string(value());
}
