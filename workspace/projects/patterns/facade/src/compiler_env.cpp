#include "compiler_env.hpp"
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

Env::Ptr Env::Null = Env::create(nullptr);

Env::Env(Env::Ptr n) : _prev(n) {}

Env::Ptr Env::create(Env::Ptr n) {
    return Env::Ptr(new Env(n));
}

Env::Ptr Env::prev() { return _prev; }

void Env::put(Token::Ptr w, Id::Ptr i) 
{ 
    _table[w] = i;
}

Id::Ptr Env::get(Token::Ptr w) 
{
    std::cout << "Env::get(" << w << ") in" << std::endl;
    for (const auto& [key, val] : _table)
    {
        if (key->equals(w))
        {
            std::cout << "Env::get(" << w << ") - _table[w]: " << key->print() << " -> " << val->print() << std::endl;
            return val;
        }

    }
    std::cout << "Env::get(" << w << ") out"  << std::endl;
    return _prev != Env::Null ? _prev->get(w) : nullptr;
}

std::string Env::to_string(std::string prefix) const
{
    std::stringstream sout;
    std::string subfix = prefix + "";

    sout << "[";
    for (auto const& [key, value] : _table)
        sout << key << " -> " << value->to_string(subfix) << ", ";
    sout << "]";

    return sout.str();
}

bool Env::operator==(const Env& that) const
{
    return (_prev == that._prev) && (_table == that._table);
}

bool Env::operator!=(const Env& that) const
{
    return !operator==(that);
}

bool Env::operator==(const Env::Ptr that) const { return operator==(*that.get()); }
bool Env::operator!=(const Env::Ptr that) const { return operator!=(*that.get()); } 

std::ostream& operator<<(std::ostream& out, Env& that)
{
    out << that.to_string();
    return out;
}

std::ostream& operator<<(std::ostream& out, Env::Ptr that)
{
    return operator<<(out, *that.get());
}
