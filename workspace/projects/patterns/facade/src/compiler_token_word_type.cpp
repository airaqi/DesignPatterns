#include "compiler_token_word_type.hpp"
#include "compiler_tag.hpp"
#include <format>
#include <memory>
#include <ostream>

Type::Ptr Type::Int = Type::create("int", Tag::BASIC, 4);
Type::Ptr Type::Float = Type::create("float", Tag::BASIC, 8);
Type::Ptr Type::Char = Type::create("char", Tag::BASIC, 1);
Type::Ptr Type::Bool = Type::create("bool", Tag::BASIC, 1);
Type::Ptr Type::Null = Type::create("null", Tag::BASIC, 0);

Type::Type(std::string s, Tag::Kind tag, int w) : 
    Word(s, tag), _width(w), _name(s) {}


Type::Ptr Type::create(std::string s, Tag::Kind tag, int w)
{
    return std::make_shared<Type>(s, tag, w);
}

Token::Ptr Type::clone()
{
    return std::make_shared<Type>(_name, tag(), _width);
}

int Type::width() const
{
    return _width;
}

std::string Type::name() const
{
    return _name;
}

bool Type::numeric(Type::Ptr t)
{
    return (*t == *Type::Char || *t == *Type::Int || *t == *Type::Float) ? true : false;
}


Type::Ptr Type::max(const Type::Ptr p1, const Type::Ptr p2)
{
    if (!numeric(p1) || !numeric(p2)) 
        return Type::Null;
    else if (*p1 == *Type::Float || *p2 == *Type::Float) 
        return Type::Float;
    else if (*p1 == *Type::Int || *p2 == *Type::Int)
        return Type::Int;
    else 
        return Type::Char;
}



bool Type::equals(const Token & rhs) const
{
    const Type& that = dynamic_cast<const Type&>(rhs);
    return Word::equals(rhs) && (name() == that.name() && width() == that.width());
}

std::string Type::to_string(std::string prefix) const
{
    return std::format("{}{}", prefix, name());
}

std::string Type::print(std::string prefix) const
{
    return std::format("{}[Type({}, {}): {}]", prefix, name(), width(), Word::print());
}

bool Type::operator<(const Token& that) const
{
    const Type& t = dynamic_cast<const Type&>(that);
    return (name() < t.name()) && (width() < t.width()) && Word::operator<(that);
}

std::ostream& operator<<(std::ostream& out, Type& typ)
{
    out << typ.to_string();
    return out;
}

std::ostream& operator<<(std::ostream& out, Type::Ptr tok)
{
    return operator<<(out, *tok.get());
}

bool operator==(const Type& lhs, const Type& rhs)           { return (lhs.equals(rhs)); }
bool operator!=(const Type& lhs, const Type& rhs)           { return !(lhs == rhs); }
