#include "compiler_token_word_type_array.hpp"
#include <format>
#include <memory>
#include <string>


Array::Array(int sz, Type::Ptr t) : Type("[]", Tag::INDEX, sz * t->width()), _size(sz), _of(t) {}


Array::Ptr Array::create(int sz, Type::Ptr t)
{
    return std::make_shared<Array>(sz, t);
}

Type::Ptr Array::of() const                 { return _of; }
void Array::of(Type::Ptr t)                 { _of = t; }
int  Array::size() const                    { return _size; }
void Array::size(int sz)                    { _size = sz; }

bool Array::equal(const Array& rhs) const
{
    return (rhs._size == _size && rhs._of == _of);
}

std::string Array::to_string(std::string prefix) const
{
    return std::format("{}[{}]{}", prefix, size(), of()->to_string());
}

std::string Array::print(std::string prefix) const
{
    return std::format("{}[Array({}): {}]", prefix, size(), of()->to_string());
}


bool operator==(const Array& lhs, const Array& rhs)
{
    return lhs.equal(rhs);
}


bool operator!=(const Array& lhs, const Array& rhs)
{
    return !(lhs == rhs);
}
