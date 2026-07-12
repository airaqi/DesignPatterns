#ifndef __COMPILER_PROGRAM_NODE_NUMERIC_H__
#define __COMPILER_PROGRAM_NODE_NUMERIC_H__ 

#include "program_node_expr_value.hpp"

class NumericNode : public ValueNode
{
    public:
        NumericNode(double val) : _value(val) {}

        void value(double val)      { _value = val; }    
        double value() const        { return _value; }

        virtual std::string to_string() const override;

    protected:
        virtual void parse(Parser&) override;

    private:
        double _value;
};
#endif /* ifndef __COMPILER_PROGRAM_NODE_NUMERIC_H__ */
