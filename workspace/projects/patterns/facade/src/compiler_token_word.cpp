#include "compiler_token_word.hpp"
#include "compiler_tag.hpp"
#include "compiler_token.hpp"
#include <format>
#include <iostream>
#include <ostream>
#include <string>

Word::Ptr Word::And     = Word::create("&&", Tag::AND);
Word::Ptr Word::Or      = Word::create("||", Tag::OR);
Word::Ptr Word::eq      = Word::create("==", Tag::EQ);
Word::Ptr Word::ne      = Word::create("!=", Tag::NE);
Word::Ptr Word::ge      = Word::create(">=", Tag::GE);
Word::Ptr Word::le      = Word::create("<=", Tag::LE);
Word::Ptr Word::minus   = Word::create("minus", Tag::MINUS);
Word::Ptr Word::True    = Word::create("true", Tag::TRUE);
Word::Ptr Word::False   = Word::create("false", Tag::FALSE);
Word::Ptr Word::temp    = Word::create("t", Tag::TEMP);

Word::Ptr Word::ambr    = Word::create("&", Tag::AMBR);
Word::Ptr Word::pipe    = Word::create("|", Tag::PIPE);
Word::Ptr Word::asgn    = Word::create("=", Tag::ASGN);
Word::Ptr Word::Not     = Word::create("!", Tag::NOT);
Word::Ptr Word::gt      = Word::create(">", Tag::GT);
Word::Ptr Word::lt      = Word::create("<", Tag::LT);

Word::Ptr Word::scln    = Word::create(";", Tag::SCLN);
Word::Ptr Word::cubo    = Word::create("{", Tag::CUBO);
Word::Ptr Word::cubc    = Word::create("}", Tag::CUBC);
Word::Ptr Word::paro    = Word::create("(", Tag::PARO);
Word::Ptr Word::parc    = Word::create(")", Tag::PARC);
Word::Ptr Word::sqbo    = Word::create("[", Tag::SQBO);
Word::Ptr Word::sqbc    = Word::create("]", Tag::SQBC);
Word::Ptr Word::plus    = Word::create("+", Tag::PLUS);
Word::Ptr Word::hyph    = Word::create("-", Tag::HYPH);
Word::Ptr Word::mult    = Word::create("*", Tag::MULT);
Word::Ptr Word::slsh    = Word::create("/", Tag::SLSH);
Word::Ptr Word::idx     = Word::create("[]", Tag::INDEX);

Word::Word(std::string s, Tag::Kind kind) : Token(kind), _value(s) {}

Word::Ptr Word::create(std::string s, Tag::Kind kind)
{
    return Word::Ptr(new Word(s, kind));
}

Token::Ptr Word::clone()
{
    return Word::Ptr(new Word(_value, tag()));
}

std::string Word::value() const { return _value; }

std::string Word::to_string(std::string prefix) const
{
    return std::format("{}", value());
}

std::string Word::print(std::string prefix) const
{
    return std::format("{}[Word({}): {}]", prefix, value(), Token::print());
}


bool Word::equals(const Token& rhs) const
{
    const Word& r = dynamic_cast<const Word&>(rhs);
    //std::cout << "Word::equals(" << rhs.print() << ") this: " << this->print() 
        //<< " equals: " << (r.value() == value())
        //<< std::endl;
    return Token::equals(rhs) && (r.value() == value());
}

bool Word::equals(const Token::Ptr that) const
{
    return equals(*that);
}

bool Word::operator<(const Token& that) const
{
    const Word& t = static_cast<const Word&>(that);
    //std::cout << "Word::operator<() - value: " << _value << " that.value: " << t._value << std::endl;
    return Token::operator<(that) && (_value < t._value);
}

std::ostream& operator<<(std::ostream& out, Word& tok)
{
    out << tok.to_string();
    return out;
}

std::ostream& operator<<(std::ostream& out, Word::Ptr that) { return operator<<(out, *that); }

bool operator==(const Word& lhs, const Word& rhs)               { return lhs.equals(rhs); }
bool operator!=(const Word& lhs, const Word& rhs)               { return !(lhs == rhs); }

