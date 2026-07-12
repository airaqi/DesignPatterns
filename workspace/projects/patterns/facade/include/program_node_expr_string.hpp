#ifndef __COMPILER_PROGRAMNODE_EXPRESSION_STRING_H__
#define __COMPILER_PROGRAMNODE_EXPRESSION_STRING_H__ 

#include "compiler_token.hpp"
#include "compiler_token_word_type.hpp"
#include "program_node_expr_value.hpp"
#include <string>

class StringNode : public ValueNode
{
    public:
        StringNode(std::string v, Token *token) 
            : ValueNode(token, new Type("string", Tag::STR, 1)), _value(v) {}

        std::string value() { return _value; }
        
        virtual std::string to_string(std::string prefix = "") const override 
        { 
            return prefix + "[String (" + std::to_string(id()) + "): " + _value + "]"; 
        }

    private:
        std::string _value;
};

#endif /* ifndef __COMPILER_PROGRAMNODE_EXPRESSION_STRING_H__ */
