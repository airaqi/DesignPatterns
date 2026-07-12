#ifndef __COMPILER_TOKEN_H__
#define __COMPILER_TOKEN_H__ 

/* Represents a parsing text token
 */
#include "compiler_tag.hpp"
#include <iostream>
#include <memory>
#include <ostream>
#include <string>

class Scanner;

class Token
{
    public:
        Token(Tag::Kind kind);

    public:
        typedef std::shared_ptr<Token> Ptr;

        static Ptr create(Tag::Kind kind);
        virtual Token::Ptr clone();
        Tag::Kind tag() const { return _tag; }

        int line();     void line(int);
        int index();    void index(int);
        int column();   void column(int);

        virtual std::string to_string(std::string = "") const;
        virtual std::string print(std::string="") const;
        virtual bool equals(const Token&) const;
        virtual bool equals(const Token::Ptr) const;

        virtual bool operator<(const Token&) const;

        friend std::ostream& operator<<(std::ostream&, Token&);
        friend std::ostream& operator<<(std::ostream&, Ptr);
        friend bool operator==(const Token&, const Token&);
        friend bool operator!=(const Token&, const Token&);

    private:
        Tag::Kind   _tag;
        int         _line;
        int         _index;
        int         _column;
};


#endif /* ifndef __COMPILER_TOKEN_H__ */
