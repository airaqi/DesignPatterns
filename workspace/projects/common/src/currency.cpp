#include "currency.h"
#include <iomanip>
#include <sstream>
#include <stdexcept>
#include <string>


bool Currency::compatible(Currency other)
{
    return (iso_code() == other.iso_code() && name() == other.name());
}


std::string Currency::to_string(std::string prefix)
{
    std::stringstream sout;
    if (prefix.length() > 0)
        sout << prefix << " ";
    sout << std::fixed << std::setprecision(2) << value();
    return sout.str();
}

bool operator==(Currency c1, Currency c2)
{
    return (c1.compatible(c2) &&
            c1.value() == c2.value());
}

Currency operator+(Currency c1, Currency c2)
{
    if (!c1.compatible(c2))
        throw std::runtime_error("Incompatible currencies, exchange rates is not available!");
    return Currency(c1.value() + c2.value(), c1.name(), c1.iso_code());
}

Currency operator-(Currency c1, Currency c2)
{
    if (!c1.compatible(c2))
        throw std::runtime_error("Incompatible currencies, exchange rates no avaiable yet!");
    return Currency(c1.value() - c2.value(), c1.name(), c1.iso_code());
}

Currency operator*(Currency c, double d)
{
    return Currency(c.value() * d, c.name(), c.iso_code());
}

Currency operator/(Currency c, double d) 
{
    return (d != 0 ? Currency(c.value() / d, c.name(), c.iso_code()) : throw std::runtime_error("Division by zero"));
}

Currency operator+=(Currency c1, Currency c2)
{
    return c1 + c2;
}

Currency operator-=(Currency c1, Currency c2)
{
    return c1 - c2;
}

Currency operator*=(Currency c1, double d)
{
    return c1 * d;
}

Currency operator/=(Currency c1, double d)
{
    return c1 / d;
}
