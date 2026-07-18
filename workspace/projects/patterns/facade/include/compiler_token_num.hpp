#ifndef __COMPILER_TOKEN_NUM_H__
#define __COMPILER_TOKEN_NUM_H__ 

#include "compiler_token.hpp"
#include <memory>
#include <ostream>
#include <string>

class Num : public Token
{
    public:
        typedef std::shared_ptr<Num> Ptr;

        Num(int t);

    public:
        static Ptr create(int t);

        virtual int value() const;

        virtual std::string to_string(std::string = "") const override;
        virtual std::string print(std::string = "") const override;
        virtual bool equal(const Num&) const;

        virtual bool operator<(const Token&) const override;

        friend bool operator==(const Num&, const Num&);
        friend bool operator!=(const Num&, const Num&);

        friend std::ostream& operator<<(std::ostream&, const Num&);
        friend std::ostream& operator<<(std::ostream&, const Num::Ptr);

    private: 
        int _value;
};

typedef std::shared_ptr<Num> pNum;

#endif /* ifndef __COMPILER_TOKEN_NUM_H__ */
