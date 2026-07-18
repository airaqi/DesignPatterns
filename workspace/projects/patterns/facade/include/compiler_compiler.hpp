#ifndef __COMPILER_COMPILER_H__
#define __COMPILER_COMPILER_H__ 

#include "program_node_stmt.hpp"
#include <getopt.h>
#include <istream>
#include <memory>
#include <ostream>
#include <string>

class Compiler
{
    private:
        using Ptr = std::shared_ptr<Compiler>;
        static Ptr _instance;
        std::istream & _in;
        std::ostream & _out;

    public:
        Compiler(std::istream&, std::ostream&);
        static Ptr create(std::istream&, std::ostream&);

    public:
        static Ptr get_instance();
        static Ptr get_instance(std::istream&, std::ostream&);
        StmtNode::Ptr compile();

        std::istream& get_in() const;
        std::ostream& get_out() const;

    private:
        void error(int code, std::string message);

    public:

};

#endif /* ifndef __COMPILER_COMPILER_H__ */
