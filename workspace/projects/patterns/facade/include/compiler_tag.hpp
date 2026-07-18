#ifndef __COMPILER_SYMANICS_H__
#define __COMPILER_SYMANICS_H__

#include <iostream>
#include <ostream>
#include <string>

class Tag {
public:
    enum Kind 
    {

        AND = 256,
        BASIC,
        BREAK,
        DO,
        ELSE,
        EQ,
        FALSE,
        GE,
        ID,
        IF,
        INDEX,
        LE,
        MINUS,
        NE,
        NUM,
        OR,
        REAL,
        TEMP,
        TRUE,
        WHILE,

        AMBR,
        PIPE,
        ASGN,
        NOT,
        LT,
        GT,
        CUBO,
        CUBC,
        SQBO,
        SQBC,
        PARO,
        PARC,
        SCLN,
        PLUS,
        HYPH,
        MULT,
        SLSH,
        ANY,
        NONE
    };

public :
    std::string chars() { return _chars; }
    static std::string to_string(const Tag::Kind&, std::string="");

private:
    std::string _chars;

};

inline std::string Tag::to_string(const Tag::Kind &k, std::string prefix)
{
    switch (k) {
        case Tag::AND:      return "AND";
        case Tag::BASIC:    return "BASIC";    break;
        case Tag::BREAK:    return "BREAK";    break;
        case Tag::DO:       return "DO";       break;
        case Tag::ELSE:     return "ELSE";     break;
        case Tag::EQ:       return "EQ";       break;
        case Tag::FALSE:    return "FALSE";    break;
        case Tag::GE:       return "GE";       break;
        case Tag::ID:       return "ID";       break;
        case Tag::IF:       return "IF";       break;
        case Tag::INDEX:    return "INDEX";    break;
        case Tag::LE:       return "LE";       break;
        case Tag::MINUS:    return "MINUS";    break;
        case Tag::NE:       return "NE";       break;
        case Tag::NUM:      return "NUM";      break;
        case Tag::OR:       return "OR";       break;
        case Tag::REAL:     return "REAL";     break;
        case Tag::TEMP:     return "TEMP";     break;
        case Tag::TRUE:     return "TRUE";     break;
        case Tag::WHILE:    return "WHILE";    break;

        case Tag::AMBR:     return "AMBR";     break;
        case Tag::PIPE:     return "PIPE";     break;
        case Tag::ASGN:     return "ASGN";     break;
        case Tag::NOT:      return "NOT";      break;
        case Tag::LT:       return "LT";       break;
        case Tag::GT:       return "GT";       break;
        case Tag::SCLN:     return "SCLN";     break;
        case Tag::PLUS:     return "PLUS";     break;
        case Tag::HYPH:     return "HYPH";     break;
        case Tag::MULT:     return "MULT";     break;
        case Tag::SLSH:     return "SLSH";     break;
        case Tag::ANY:      return "ANY";      break;
        case Tag::NONE:     return "NONE";     break;
        case Tag::SQBO:     return "SQBO";     break;
        case Tag::SQBC:     return "SQBC";     break;
        case Tag::CUBO:     return "CUBO";     break;
        case Tag::CUBC:     return "CUBC";     break;
        default:            return "";
    }
}

inline std::ostream& operator<<(std::ostream& out, Tag::Kind &k)
{
/*    if (ks == "")*/
        /*out.setstate(std::ios::failbit);*/
    out << Tag::to_string(k);

    return out;
}

#endif /* ifndef __COMPILER_SYMANICS_H__ */
