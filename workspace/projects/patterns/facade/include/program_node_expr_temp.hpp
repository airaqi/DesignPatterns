#ifndef __COMPILER_PROGRAM_NODE_EXPR_TEMP_H__
#define __COMPILER_PROGRAM_NODE_EXPR_TEMP_H__

#include "program_node_expr.hpp"
#include <memory>
#include <string>
class TempNode : public ExprNode
{
    public: 
        typedef std::shared_ptr<TempNode> Ptr;

    private:
        inline static int   _count = 0;
        int                 _number;

    public:
        TempNode(Type::Ptr p);

    public:
        static Ptr create(Type::Ptr p);

        virtual std::string to_string(std::string prefix="");

};

#endif // __COMPILER_PROGRAM_NODE_EXPR_TEMP_H__
