#include "compiler_scanner.hpp"
#include "compiler_tag.hpp"
#include "compiler_token.hpp"
#include "compiler_token_real.hpp"
#include "compiler_token_num.hpp"
#include "compiler_token_word.hpp"
#include "compiler_token_word_type.hpp"
#include <cctype>
#include <format>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <unistd.h>

int Scanner::_line = 0;
int Scanner::_index = 0;
int Scanner::_column = 0;
int Scanner::_prev_col = 0;

Scanner::Scanner(std::istream& in) 
    : _in(in), _empty(true), _peek(' ') 
{
    reserve(Word::create("if", Tag::IF));
    reserve(Word::create("else", Tag::ELSE));
    reserve(Word::create("while", Tag::WHILE));
    reserve(Word::create("do", Tag::DO));
    reserve(Word::create("break", Tag::BREAK));
    reserve(Word::True);
    reserve(Word::False);
    reserve(Type::Int);
    reserve(Type::Char);
    reserve(Type::Float);
    reserve(Type::Bool);

}

Scanner::~Scanner() 
{
    reset();
}

void Scanner::reserve(Word::Ptr word) 
{
    _words.insert_or_assign(word->value(), word);
}

Word::Ptr Scanner::find(std::string s) 
{
    Word::Ptr word = _words.find(s) != _words.end() ? _words[s] : Type::Null;
    std::cout << "Scanner::find() s: " << s << " word: " << word << std::endl;
    return word;
}

void Scanner::putback(Token::Ptr t)
{
    //if (_empty) std::cout << "putback() into a full buffer" << "\n";
    _buf.push_back(t);
    _buffer = t;
    _empty = false;
    std::cout << "<<- " << t << "\n";
}

char Scanner::increment(char c)
{
    _index++;
    _prev_col = _column++;
    if (c == '\n') 
    {
        _line++;
        _column = 0;
    }

    //std::cout << "Scanner::increment('" << c << "') " << _index << " (" << _line << ", " << _column << ")\n";

    return c;
}

char Scanner::decrement(char c)
{
    _index--;
    _column--;
    if (c == '\n')
    {
        _line--;
        _column = _prev_col;
    }
    return c;
}

std::string Scanner::write(char c)
{
    switch(c)
    {
        case '\n':
            return std::string("\\n");
        default:
            return  std::format("{}", c);
    }
}

int Scanner::line() { return _line; }
int Scanner::index() { return _index; }
int Scanner::column() { return _column; }

void Scanner::reset()
{
    _index = 0;
    _line = 0;
    _column = 0;
    _prev_col = 0;
}

char Scanner::read()
{
    _in >> std::noskipws >> _peek;
    return increment(_peek);
}

int Scanner::dread(double& val)
{
    _in >> val;
    std::string sval = std::to_string(val);
    int count = sval.length();
    std::cout << "Scanner::dread(" << val << ") - val = " << sval << "count = " << count << "\n";
    _index += count;
    _column += count;
    _peek = ' ';
    return count;
}

auto& Scanner::read(char& c)
{
    auto& ret = _in.get(c);
    increment(c);
    _peek = c;
    return ret;
}

bool Scanner::readch(char c)
{
    char temp = _peek;
    read();
    if (_peek != c) 
    {
        putback(_peek);
        _peek = temp;
        return false;
    }
    _peek = ' ';
    return true;
}

Token::Ptr Scanner::scan(std::string logo)
{
    auto t = get();
    std::cout << "--> Scanner::scan(" << logo << ") " << t << " " << logo << "\n";
    return t;
}

Token::Ptr Scanner::get()
{
    if(!_buf.empty())
    {
        _buffer = _buf.back();
        _buf.pop_back();
        _empty = true;
        return _buffer;
    }

    do
    {
        read();
        if (isspace(_peek) || _peek == '\t' || _peek == '\n') 
            continue;
        else
            break;
    } while (!eof());

    switch(_peek)
    {
        case '&':
           return (readch('&')) ? Word::And->clone() : Word::ambr->clone();

        case '|':
           return (readch('|')) ? Word::Or->clone() : Word::pipe->clone();

        case '=':
           return (readch('=')) ? Word::eq->clone() : Word::asgn->clone();

        case '!':
           return (readch('=')) ? Word::ne->clone() : Word::Not->clone();

        case '<':
           return (readch('=')) ? Word::le->clone() : Word::lt->clone();

        case '>':
           return (readch('=')) ? Word::ge->clone() : Word::gt->clone();

        case ';':   return Word::scln->clone();
        case '{':   return Word::cubo->clone();
        case '}':   return Word::cubc->clone();
        case '(':   return Word::paro->clone();
        case ')':   return Word::parc->clone();
        case '[':   return Word::sqbo->clone();
        case ']':   return Word::sqbc->clone();

        case '+':   return Word::plus->clone();
        case '-':   return Word::hyph->clone();
        case '*':   return Word::mult->clone();
        case '/':   return Word::slsh->clone();
    }

    if (std::isdigit(_peek))
    {
        int v = 0;
        do
        {
            int c = _peek - '0';
            v = 10 * v + c;
            read();
        } while (isdigit(_peek) && !eof());

        if (_peek != '.') 
        {
            putback(_peek);
            _peek = ' ';
            return Num::create(v);
        }

        float x = v, d = 10;
        for(;!eof();) 
        {
            read();
            if (!isdigit(_peek)) 
            {
                putback(_peek);
                break;
            }
            int c = _peek - '0';
            x += c / d;
            d = d * 10;
        }

        return Real::create(x);
    }

    if (std::isalpha(_peek))
    {
        std::stringstream ss;
        do 
        {
            ss << _peek;
            read();
            std::cout << "Scanner::get() _peek: " << _peek << " ss: " << ss.str() << std::endl;
        } while ((isalnum(_peek) || _peek == '_') && !eof());

        if (!eof()) putback(_peek);
        std::string s = ss.str();
        Word::Ptr word = find(s);
        if (word != Type::Null)
            return word->clone();
        word = Word::create(s, Tag::ID);
        reserve(word);
        return word;
    }

    return Word::create(std::string(1, _peek), Tag::ANY);
    
    // TODO refactor out
    /*if (_sym.chars().find_first_of(_peek) <= _sym.chars().length()) 
    {
        char c;
        std::string s1, s2;

        c = _in.peek();
        s1 += _peek;
        s2 += _peek;
        s2 += c;

        Tag::Kind k = _sym.nTermKind(s2);
        if (k != Tag::NONE)
        {
            read(_peek);
            return *new Word( s2, k);
        }
        k = _sym.nTermKind(s1);
        if (k != Tag::NONE)
            return *new Token(k, s1);

        //_in.putback(c);
        return *new Token(_sym._OPER, std::to_string(_peek));
    }
    
    // TODO refactor out
    else if (std::isdigit(_peek))
    {
        putback(_peek);
        double val;
        int len = dread(val);
        int ival = val;
        if (ival == val)
            return *new Num(ival);
        // TODO -8 is numeric kind, need to be changed 
        return *new Real(val);
    }
    
    // TODO refactor out
    else if (std::isspace(_peek))
    {
        //std::cout << static_cast<int>(ch) << "\n";
        increment(_peek);
        return get();
    }
    else if (std::isalpha(_peek))
    {
        std::string s;
        s += _peek;
        while (read(_peek) && _sym.isLegalId(_peek))
            s += _peek;
        putback(_peek);

        Tag::Kind k = _sym.termKind(s);
        if (k != Tag::NONE)
            return *new Word(s, k);

        return *new Token(_sym._NTERM, s);
    }

    return *new Token(_sym.OPER, std::to_string(_peek));*/
}

bool Scanner::eof()
{
    //std::cout << (char)_in.peek() << " " << _in.eof() << " " << _in.good() << "\n";
    //return ((_in.peek() == -1 || _in.eof()) && _empty);
    //return !_in.good();
    return _in.eof() && _empty;
}

void Scanner::putback(char ch)
{
    _in.putback(decrement(ch));
}


