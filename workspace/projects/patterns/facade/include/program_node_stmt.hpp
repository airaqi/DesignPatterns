#ifndef __COMPILER_PROGRAM_NODE_STATEMENT_H__
#define __COMPILER_PROGRAM_NODE_STATEMENT_H__ 

#include "compiler_code_generator.hpp"
#include "program_node.hpp"
#include <iostream>
#include <memory>
#include <ostream>

/* Represents a statement of the system such as 
 * if, else, ...etc.
 */
class StmtNode : public ProgNode, public std::enable_shared_from_this<StmtNode>
{
    public:
        typedef std::shared_ptr<StmtNode> Ptr;

    private:
        int _after;

    public:
        // static const StmtNode::Ptr Null;
        static StmtNode::Ptr Enclosing;

        static const StmtNode::Ptr Null();


        StmtNode();

    public:
        virtual ~StmtNode() = default;

    public:
        static Ptr create();

        void after(int a) { _after = a; }   int after() { return _after; }

        virtual void traverse(CodeGenerator&) override;

        virtual void add(ProgNode::Ptr) override;
        virtual void remove(ProgNode::Ptr) override;
        virtual const ProgNode& child(const int) const override;
        virtual void getSourcePosition(int &l, int &i) override;
        virtual bool is_equals(const ProgNode &) const override;

        virtual void gen(int b, int a) {}

        virtual bool isStatement() override;

        virtual std::string to_string(std::string = "") const override;
        virtual std::string print(std::string = "") const override;

        friend std::ostream& operator<<(std::ostream&, const StmtNode&);
        friend std::ostream& operator<<(std::ostream&, const StmtNode::Ptr);
};

#endif /* ifndef __COMPILER_PROGRAM_NODE_STATEMENT_H__ */
