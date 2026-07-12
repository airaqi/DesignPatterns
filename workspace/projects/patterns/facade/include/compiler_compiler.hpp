#ifndef __COMPILER_COMPILER_H__
#define __COMPILER_COMPILER_H__ 

#include "compiler_byte_code.hpp"
#include <istream>
#include <sstream>
#include <string>

class Compiler
{
    public:
        Compiler();

        virtual void compile(std::istream&, ByteCodeStream&);

    private:
        void error(int code, std::string message);
        int find_arg(const std::string option, int argc, char *argv[]);
        std::stringstream& load_file(std::string filename, std::stringstream& stream);
        std::string usage();
        std::string print_args(int argc, char *argv[]);
};

#endif /* ifndef __COMPILER_COMPILER_H__ */
