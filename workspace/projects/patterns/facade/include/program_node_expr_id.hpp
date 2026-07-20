#ifndef __COMPILER_PROGRAM_NODE_EXPR_ID_H__
#define __COMPILER_PROGRAM_NODE_EXPR_ID_H__ 

#include "compiler_token_word.hpp"
#include "compiler_token_word_type.hpp"
#include "program_node_expr.hpp"
#include <memory>
#include <ostream>

class Id : public ExprNode
{
    public: 
        typedef std::shared_ptr<Id> Ptr;
        typedef std::weak_ptr<Id> Wptr;

    public: 
        Id(Word::Ptr id, Type::Ptr p, int b);

    public:
        static Ptr create(Word::Ptr id, Type::Ptr p, int b);

        int offset() const;
        void offset(int);

        virtual bool is_equals(const ProgNode&) const override;
        virtual std::string to_string(std::string = "") const override;
        virtual std::string print(std::string = "") const override;

        friend bool operator==(const Id&, const Id&);
        friend bool operator==(const Id::Ptr, const Id::Ptr);
        friend bool operator!=(const Id&, const Id&);
        friend bool operator!=(const Id::Ptr, const Id::Ptr);

        friend std::ostream& operator<<(std::ostream&, const Id&);
        friend std::ostream& operator<<(std::ostream&, const Id::Ptr);

    private:
        int     _offset;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_EXPR_ID_H__ */
