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
        static Ptr& And();
        static Ptr& Or();
        static Ptr& eq();
        static Ptr& ne();
        static Ptr& le();
        static Ptr& ge();
        static Ptr& minus();
        static Ptr& True();
        static Ptr& False();
        static Ptr& temp();
        static Ptr& ambr();
        static Ptr& pipe();
        static Ptr& asgn();
        static Ptr& Not();
        static Ptr& gt();
        static Ptr& lt();
        static Ptr& scln();
        static Ptr& cubo();
        static Ptr& cubc();
        static Ptr& paro();
        static Ptr& parc();
        static Ptr& sqbo();
        static Ptr& sqbc();
        static Ptr& plus();
        static Ptr& hyph();
        static Ptr& mult();
        static Ptr& slsh();
        static Ptr& idx();

    private:
        std::string _value;
};

#endif /* ifndef __COMPILER_TOKEN_WORD_H__ */
