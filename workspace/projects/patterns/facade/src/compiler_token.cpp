#include "compiler_token.hpp"
#include "compiler_tag.hpp"
#include "compiler_scanner.hpp"
#include <format>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>

Token::Token(Tag::Kind kind) : _tag(kind), _line(Scanner::line()), _index(Scanner::index()), _column(Scanner::column()) {}

Token::Ptr Token::create(Tag::Kind kind)
{
    return std::make_shared<Token>(kind);
}

Token::Ptr Token::clone()
{
    return std::make_shared<Token>(_tag);
}

int Token::line()           { return _line; }
void Token::line(int l)     { _line = l; }
int Token::index()          { return _index; }
void Token::index(int i)    { _index = i; }
int Token::column()         { return _column; }
void Token::column(int c)   { _column = c; }

std::string Token::to_string(std::string prefix) const
{
    return std::format("{}{}", prefix, Tag::to_string(tag()));
}

std::string Token::print(std::string prefix) const 
{
    return std::format("{}[Token({})]", prefix, Tag::to_string(tag()));
}

bool Token::equals(const Token& that) const
{
    //std::cout << "Token::equals(" << that.print() << ") this: " << this->print() 
        //<< " equals: " << (tag() == that.tag()) 
        //<< std::endl;
    return (tag() == that.tag());
}

bool Token::equals(const Token::Ptr that) const
{
    //std::cout << "Token::equals(" << that->print() << ") this: " << this->print()
        //<< std::endl;
    return equals(*that);
}

bool Token::operator<(const Token& that) const 
{
    //std::cout << "Token::operator<() - tag: " << tag() << " that.tag: " << that.tag() << std::endl;
    return tag() < that.tag(); 
}

std::ostream& operator<<(std::ostream& out, Token& t)
{
    out << t.to_string();
    return out;
}

std::ostream& operator<<(std::ostream& out, Token::Ptr that)
{
    return operator<<(out, *that);
}

bool operator==(const Token& lhs, const Token& rhs)             { return lhs.equals(rhs); }
bool operator!=(const Token& lhs, const Token& rhs)             { return !(lhs == rhs); }
