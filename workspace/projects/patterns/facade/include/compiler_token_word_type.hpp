#ifndef __COMPILER_TOKEN_WORD_TYPE_H__
#define __COMPILER_TOKEN_WORD_TYPE_H__ 

#include "compiler_tag.hpp"
#include "compiler_token_word.hpp"
#include <memory>
#include <ostream>
#include <string>

class Type : public Word
{
    public: 
        typedef std::shared_ptr<Type> Ptr;

    protected:
        Type(std::string s, Tag::Kind tag, int w);

    public:
        static Ptr create(std::string, Tag::Kind, int w);

        virtual Token::Ptr clone() override;

        virtual std::string name() const;
        virtual int width() const;

        static bool numeric(const Ptr t);
        static Ptr max(const Ptr p1, const Ptr p2);

        virtual bool equals(const Token&) const override;
        virtual std::string to_string(std::string = "") const override;
        virtual std::string print(std::string = "") const override;

        virtual bool operator<(const Token&) const override;

        friend std::ostream& operator<<(std::ostream&, Type&);
        friend std::ostream& operator<<(std::ostream&, Type::Ptr);
        friend bool operator==(const Type&, const Type&);
        friend bool operator!=(const Type&, const Type&);

    public:
        static Ptr Int, Float, Char, Bool;
        static Ptr Null;

    private:
        std::string _name;
        int         _width;
};

#endif /* ifndef __COMPILER_TOKEN_WORD_TYPE_H__ */
