#ifndef __COMPILER_COMPILER_H__
#define __COMPILER_COMPILER_H__ 

#include "program_node_stmt.hpp"
#include <getopt.h>
#include <memory>
#include <sstream>
#include <string>

class Compiler
{
    public:
        using Ptr = std::shared_ptr<Compiler>;
    private:
        std::string _infile, _outfile;
        std::stringstream _in;
        std::stringstream _out;

    public:
        Compiler(std::string&, std::string&);
        static Ptr create(std::string&, std::string&);

    public:
        StmtNode::Ptr compile();

        std::stringstream& in();
        std::stringstream& out();

        void load_file(std::string& filename);
        void save(std::string& filename);

    private:
        void error(int code, std::string message);

    public:

};

#endif /* ifndef __COMPILER_COMPILER_H__ */
