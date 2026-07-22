#ifndef __COMPILER_ENV_H__
#define __COMPILER_ENV_H__ 

#include "compiler_token.hpp"
#include "program_node_expr_id.hpp"
#include <map>
#include <memory>
#include <ostream>
#include <string>

class Env
{
    public:
        typedef std::shared_ptr<Env> Ptr;
        static Env::Ptr& Null();

    public:
        Env(Ptr n);

    public:
        static Ptr create(Ptr n);

        Env::Ptr prev();

        virtual void put(Token::Ptr w, Id::Ptr i);
        virtual Id::Ptr get(const Token::Ptr w);

        virtual std::string to_string(std::string = "") const;

        bool operator==(const Env&) const;
        bool operator!=(const Env&) const;
        
        bool operator==(const Env::Ptr) const;
        bool operator!=(const Env::Ptr) const;

        friend std::ostream& operator<<(std::ostream&, Env&);
        friend std::ostream& operator<<(std::ostream&, Env::Ptr);

    protected:
        Ptr _prev;

    private:
        std::map<Token::Ptr, Id::Ptr>   _table;
};

#endif /* ifndef __COMPILER_ENV_H__ */
