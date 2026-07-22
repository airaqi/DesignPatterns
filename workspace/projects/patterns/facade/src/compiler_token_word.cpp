#include "compiler_token_word.hpp"
#include "compiler_tag.hpp"
#include "compiler_token.hpp"
#include <format>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>

Word::Ptr& Word::And() { static Word::Ptr instance = Word::create("&&", Tag::AND); return instance; }
Word::Ptr& Word::Or() { static Word::Ptr instance = Word::create("||", Tag::OR); return instance; }
Word::Ptr& Word::eq() { static Word::Ptr instance = Word::create("==", Tag::EQ); return instance; }
Word::Ptr& Word::ne() { static Word::Ptr instance = Word::create("!=", Tag::NE); return instance; }
Word::Ptr& Word::le() { static Word::Ptr instance = Word::create("<=", Tag::LE); return instance; }
Word::Ptr& Word::ge() { static Word::Ptr instance = Word::create(">=", Tag::GE); return instance; }
Word::Ptr& Word::minus() { static Word::Ptr instance = Word::create("minus", Tag::MINUS); return instance; }
Word::Ptr& Word::True() { static Word::Ptr instance = Word::create("true", Tag::TRUE); return instance; }
Word::Ptr& Word::False() { static Word::Ptr instance = Word::create("false", Tag::FALSE); return instance; }
Word::Ptr& Word::temp() { static Word::Ptr instance = Word::create("t", Tag::TEMP); return instance; }

Word::Ptr& Word::ambr() { static Word::Ptr instance = Word::create("&", Tag::AMBR); return instance; }
Word::Ptr& Word::pipe() { static Word::Ptr instance = Word::create("|", Tag::PIPE); return instance; }
Word::Ptr& Word::asgn() { static Word::Ptr instance = Word::create("=", Tag::ASGN); return instance; }
Word::Ptr& Word::Not() { static Word::Ptr instance = Word::create("!", Tag::NOT); return instance; }
Word::Ptr& Word::gt() { static Word::Ptr instance = Word::create(">", Tag::GT); return instance; }
Word::Ptr& Word::lt() { static Word::Ptr instance = Word::create("<", Tag::LT); return instance; }
Word::Ptr& Word::scln() { static Word::Ptr instance = Word::create(";", Tag::SCLN); return instance; }
Word::Ptr& Word::cubo() { static Word::Ptr instance = Word::create("{", Tag::CUBO); return instance; }
Word::Ptr& Word::cubc() { static Word::Ptr instance = Word::create("}", Tag::CUBC); return instance; }
Word::Ptr& Word::paro() { static Word::Ptr instance = Word::create("(", Tag::PARO); return instance; }
Word::Ptr& Word::parc() { static Word::Ptr instance = Word::create(")", Tag::PARC); return instance; }
Word::Ptr& Word::sqbo() { static Word::Ptr instance = Word::create("[", Tag::SQBO); return instance; }
Word::Ptr& Word::sqbc() { static Word::Ptr instance = Word::create("]", Tag::SQBC); return instance; }
Word::Ptr& Word::plus() { static Word::Ptr instance = Word::create("+", Tag::PLUS); return instance; }
Word::Ptr& Word::hyph() { static Word::Ptr instance = Word::create("-", Tag::HYPH); return instance; }
Word::Ptr& Word::mult() { static Word::Ptr instance = Word::create("*", Tag::MULT); return instance; }
Word::Ptr& Word::slsh() { static Word::Ptr instance = Word::create("/", Tag::SLSH); return instance; }
Word::Ptr& Word::idx() { static Word::Ptr instance = Word::create("[]", Tag::INDEX); return instance; }


Word::Word(std::string s, Tag::Kind kind) : Token(kind), _value(s) {}

Word::Ptr Word::create(std::string s, Tag::Kind kind)
{
    return std::make_shared<Word>(s, kind);
}

Token::Ptr Word::clone()
{
    return make_shared<Word>(_value, tag());
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

