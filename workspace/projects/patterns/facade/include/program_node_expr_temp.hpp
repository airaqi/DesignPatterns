#ifndef __COMPILER_PROGRAM_NODE_EXPR_TEMP_H__
#define __COMPILER_PROGRAM_NODE_EXPR_TEMP_H__

#include "program_node_expr.hpp"
#include <format>
#include <memory>
#include <string>
class TempNode : public ExprNode
{
    public: 
        typedef std::shared_ptr<TempNode> Ptr;

    private:
        inline static int  _count = 0;
        int         _number;

    protected:
        TempNode(Type::Ptr p) : ExprNode(Word::temp, p), _number(++_count) {}

    public:
        static Ptr create(Type::Ptr p) { return Ptr(new TempNode(p)); }

        virtual std::string to_string(std::string prefix="") { return std::format("t{}", _number); }

};

#endif // __COMPILER_PROGRAM_NODE_EXPR_TEMP_H__
