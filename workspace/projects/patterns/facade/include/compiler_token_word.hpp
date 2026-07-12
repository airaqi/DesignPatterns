#ifndef __COMPILER_TOKEN_WORD_H__
#define __COMPILER_TOKEN_WORD_H__ 

#include "compiler_tag.hpp"
#include "compiler_token.hpp"
#include <memory>
#include <ostream>
#include <string>

class Word : public Token
{
    public:
        typedef std::shared_ptr<Word> Ptr;
    protected:
        Word(std::string s, Tag::Kind kind);

    public:
        static Ptr create(std::string, Tag::Kind);
        virtual Token::Ptr clone() override;

        virtual std::string value() const;

        virtual std::string to_string(std::string = "") const override;
        virtual std::string print(std::string = "") const override;

        virtual bool equals(const Token&) const override;
        virtual bool equals(const Token::Ptr) const override;

        virtual bool operator<(const Token&) const override;

        friend std::ostream& operator<<(std::ostream&, Word&);
        friend std::ostream& operator<<(std::ostream&, Word::Ptr);

        friend bool operator==(const Word&, const Word&);
        friend bool operator!=(const Word&, const Word&);

    public:
        static Ptr 
            And, Or, eq, ne, le, ge, minus, True, False, temp, 
            ambr, pipe, asgn, Not, gt, lt, 
            scln, cubo, cubc, paro, parc, sqbo, sqbc,
            plus, hyph, mult, slsh,
            idx;

    private:
        std::string _value;
};

#endif /* ifndef __COMPILER_TOKEN_WORD_H__ */
