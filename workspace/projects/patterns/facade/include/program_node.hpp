#ifndef __COMPILER_PROGRAM_NODE_H__
#define __COMPILER_PROGRAM_NODE_H__ 

#include "compiler_code_generator.hpp"
#include <iostream>
#include <memory>
#include <ostream>
#include <sstream>
#include <string>

/* Base composite of program nodes.
 */
class ProgNode
{
    public:
        typedef std::shared_ptr<ProgNode> Ptr;

    protected:
        ProgNode();

    public:
        virtual ~ProgNode();
        // program node manipulation
        virtual void getSourcePosition(int& l, int& i) = 0;

        // child manipulation
        virtual void add(Ptr) = 0;
        virtual void remove(Ptr) = 0;
        virtual const ProgNode& child(const int) const = 0;

        virtual void define(std::string, ProgNode::Ptr);
        virtual void undefine(std::string);
        virtual bool exists(std::string);
        virtual ProgNode::Ptr get(std::string);

        virtual void traverse(CodeGenerator&) = 0;

        virtual bool isExpression();
        virtual bool isStatement();
        virtual bool isBlock();
        virtual bool isValue();
        virtual bool isVariable();
        
        int id() const;         void id(int id);
        int line() const;       void line(int l);
        int index() const;      void index(int n);

        virtual ProgNode::Ptr scope() const;
        virtual void scope(ProgNode::Ptr s);

        virtual void error(std::string s);
        virtual void emitlabel(int);
        virtual void emit(std::string) const;

        virtual int newlabel();

        virtual std::string to_string(std::string = "") const = 0;
        virtual std::string print(std::string = "") const = 0;

        virtual bool equals(const ProgNode&) const = 0;

        virtual bool operator==(const ProgNode&) const;
        virtual bool operator!=(const ProgNode&) const;

        friend std::ostream& operator<<(std::ostream& out, const ProgNode& that);
        friend std::ostream& operator<<(std::ostream&, const ProgNode::Ptr);

        static int next_id();
        static std::stringstream& out();

    private:
        int             _id;
        int             _line;
        int             _index;
        static int      _next_id;
        static int      _labels;
        ProgNode::Ptr   _scope;
        static std::stringstream _out;
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_H__ */
