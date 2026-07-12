#include "compiler_token_real.hpp"
#include <format>
#include <string>


Real::Real(float v) : Token(Tag::REAL), _value(v) {}

std::shared_ptr<Real> Real::create(float v)
{
    return std::shared_ptr<Real>(new Real(v));
}

float Real::value() const { return _value; }


bool Real::equal(const Real& rhs) const
{
    return (rhs._value == _value);
}

std::string Real::to_string(std::string prefix) const
{
    return std::format("{}{}", prefix, value());
}

std::string Real::print(std::string prefix) const
{
    return std::format("{}[Real({}): {}]", prefix, value(), Token::print());
}


bool operator==(const Real& lhs, const Real& rhs)
{
    return lhs.equal(rhs);
}
