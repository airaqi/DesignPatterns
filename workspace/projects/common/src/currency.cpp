#include "currency.h"
#include <iomanip>
#include <iostream>
#include <ostream>
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

bool operator==(Currency lhs, Currency rhs)
{
    return (lhs.compatible(rhs) &&
            lhs.value() == rhs.value());
}

Currency operator+(Currency lhs, const Currency &rhs)
{
    lhs += rhs;
    return lhs;
}

Currency operator-(Currency lhs, const Currency &rhs)
{
    lhs -= rhs;
    return lhs;
}

Currency operator*(Currency lhs, double rhs)
{
    lhs *= rhs;
    return lhs;
}

Currency operator/(Currency lhs, double rhs) 
{
    lhs /= rhs;
    return lhs;
}

Currency& Currency::operator+=(const Currency &rhs)
{
    if (!compatible(rhs))
        throw std::runtime_error("ERROR: Incompatible currencies, exchange rates non available yet!");
    _value += rhs._value;
    return *this;
}

Currency& Currency::operator-=(const Currency& rhs)
{
    if (!compatible(rhs))
        throw std::runtime_error("ERROR: Incompatible currencies, exchange rates not avaiable yet!");
    _value -= rhs._value;
    return *this;
}

Currency& Currency::operator*=(const double rhs)
{
    _value *= rhs;
    return *this;
}

Currency& Currency::operator/=(const double rhs)
{
    if (!rhs)
        throw std::runtime_error("ERROR: Devision by zero!");

    _value /= rhs;
    return *this;
}

std::ostream& operator<<(std::ostream& sout, Currency& that)
{
    sout << that.to_string();
    return sout;
}
