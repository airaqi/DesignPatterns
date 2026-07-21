#ifndef __COMPILER_TOKEN_REAL_H__
#define __COMPILER_TOKEN_REAL_H__ 

#include "compiler_token.hpp"
#include <memory>
#include <ostream>

class Real : public Token
{

    typedef std::shared_ptr<Real> Ptr;

    protected:
        Real(float v);

    public:
        static Ptr create(float v);

        virtual float value() const;

        virtual bool equal(const Real&) const;
        virtual std::string to_string(std::string = "") const override;
        virtual std::string print(std::string = "") const override;

        friend bool operator==(const Real&, const Real&);
        friend bool operator!=(const Real&, const Real&);

        friend std::ostream& operator<<(std::ostream&, const Real&);

    private:
        float _value;
};

#endif /* ifndef __COMPILER_TOKEN_REAL_H__ */
