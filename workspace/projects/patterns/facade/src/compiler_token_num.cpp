#include "compiler_token_num.hpp"
#include <format>
#include <memory>
#include <ostream>
#include <string>


Num::Num(int t) : Token(Tag::NUM), _value(t) {}

Num::Ptr Num::create(int t)
{
    return std::make_shared<Num>(t);
}

int Num::value() const {return _value;}

std::string Num::to_string(std::string prefix) const
{
    return std::format("{}{}", prefix, value());
}

std::string Num::print(std::string prefix) const
{
    return std::format("{}[Num({}): {}]", prefix, value(), Token::print());
}

bool Num::operator<(const Token& that) const
{
    const Num& t = dynamic_cast<const Num&>(that);
    return value() < t.value() && Token::operator<(that);
}

bool Num::equal(const Num &rhs) const                       { return (rhs._value == _value); }
bool operator==(const Num& l, const Num& r)                 { return l.equal(r); }
bool operator!=(const Num& l, const Num& r)                 { return !(l == r); }

std::ostream& operator<<(std::ostream& out, const Num& that)      { out << that.to_string(); return out; }
std::ostream& operator<<(std::ostream& out, const Num::Ptr that)  { return operator<<(out, *that); }
