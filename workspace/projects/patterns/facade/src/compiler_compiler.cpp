#include "compiler_compiler.hpp"
#include "compiler_code_generator.hpp"
#include "compiler_parser.hpp"
#include "compiler_scanner.hpp"
#include "program_node_builder.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <format>

// Color codes
static const std::string ANSI_RESET = "\u001B[0m";
static const std::string ANSI_RED = "\u001B[31m";


// Commandline options
static const std::string OPT_HELP = "-h";
static const std::string OPT_INTERACT = "-i";

// error messages
static const std::string ERR_PREFIX = "Error: ";
static const std::string ERR_INVALID_OPTION = "Not a valid option";
static const std::string ERR_FILE_NOT_FOUND = "File not found, check file path";



Compiler::Compiler()
{
}


void Compiler::compile(std::istream& in, ByteCodeStream& out)
{
    Scanner scanner(in);
    ProgramNodeBuilder builder;
    Parser parser(scanner, builder);

    StmtNode::Ptr s = parser.parse();
    std::cout << s << std::endl;

/*    CodeGenerator generator(out);*/
    /*ProgramNode* parseTree = builder.getRootNode();*/
    /*parseTree->traverse(generator);*/
}

void Compiler::error(int code, std::string message) 
{
    std::cout << ANSI_RED << ERR_PREFIX << message << ANSI_RESET << std::endl;
    exit(code);
}

int Compiler::find_arg(const std::string option, int argc, char *argv[])
{
    for(int i = 0; i < argc; i++)
        if (option == argv[i])
            return i;
    return -1;
}

std::stringstream& Compiler::load_file(std::string filename, std::stringstream& out)
{
    std::ifstream inputfile(filename);
    if (!inputfile.is_open())
        error(1, ERR_FILE_NOT_FOUND);

    out << inputfile.rdbuf();

    inputfile.close();

    return out;
}

std::string Compiler::usage()
{
    std::string strformat = "{}\n\t{}\n";
    std::string optionsFormat = "\t{:<15}{}\n";
    std::string synopsis = std::vformat(strformat, std::make_format_args("Synopsis:", "Compiles input file"));
    std::string syntax = std::vformat(strformat, std::make_format_args("Syntax:", "facade_app [-h][-i][<sourcefile>]"));

    std::stringstream options;
    options << std::vformat(optionsFormat, std::make_format_args("-i", "Interactive mode"));
    options << std::vformat(optionsFormat, std::make_format_args("-h", "Print help and exit"));
    options << std::vformat(optionsFormat, std::make_format_args("-v", "Go verbose"));
    options << std::vformat(optionsFormat, std::make_format_args("sourcefile", "Input code file path"));
    
    std::stringstream sout;
    sout << synopsis << std::endl << syntax << std::endl << options.str() << std::endl;
    return sout.str();

}

std::string Compiler::print_args(int argc, char *argv[])
{
    std::stringstream sout;
    sout << argc << " [";
    if (argc >= 1)
        sout << argv[0];

    for (int i = 1; i < argc; i++)
        sout << ", "<< argv[i];

    sout << "]" << std::endl;
    return sout.str();
}
