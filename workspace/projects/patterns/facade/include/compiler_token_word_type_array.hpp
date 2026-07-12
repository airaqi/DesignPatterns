#ifndef __COMPILER_TOKEN_WORD_TYPE_ARRAY_H__
#define __COMPILER_TOKEN_WORD_TYPE_ARRAY_H__ 

#include "compiler_token_word_type.hpp"
#include <memory>
#include <string>

class Array : public Type
{
    public:
        typedef std::shared_ptr<Array> Ptr;

    protected:
        Array(int, Type::Ptr);

    public:
        static Ptr create(int, Type::Ptr);

        Type::Ptr of() const;           void of(Type::Ptr);
        int size() const;               void size(int);

        virtual bool equal(const Array&) const;

        virtual std::string to_string(std::string = "") const override;
        virtual std::string print(std::string = "") const override;

        friend bool operator==(const Array&, const Array&);
        friend bool operator!=(const Array&, const Array&);

    private:
        Type::Ptr               _of;
        int                     _size = 1;
};

#endif /* ifndef __COMPILER_TOKEN_WORD_TYPE_ARRAY_H__ */
