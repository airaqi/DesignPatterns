#include "compiler_compiler.hpp"
#include "compiler_code_generator.hpp"
#include "compiler_parser.hpp"
#include "compiler_scanner.hpp"
#include "plog/Log.h"
#include "program_node_builder.hpp"
#include <filesystem>
#include <format>
#include <fstream>
#include <iostream>
#include <memory>
#include <ostream>
#include <sstream>
#include <string>

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
static const std::string INF_FILE_NAME_NOT_FOUND = "File '{}' not found, and will be created";

Compiler::Compiler(std::string& infile, std::string& outfile) : _infile(infile), _outfile(outfile) 
{
    if (std::filesystem::exists(infile))
      load_file(infile); 
    std::filesystem::path filepath(outfile);

    if (!std::filesystem::exists(filepath.parent_path())) 
    {
      PLOGI << std::vformat(INF_FILE_NAME_NOT_FOUND, std::make_format_args(outfile));
    }
}

Compiler::Ptr Compiler::create(std::string& in, std::string& out) 
{
  return std::make_shared<Compiler>(in, out);
}

std::stringstream& Compiler::in() { return _in; }
std::stringstream& Compiler::out() { return _out; }

void Compiler::load_file(std::string& filename) 
{
    std::ifstream inputfile(std::filesystem::absolute(filename));
    if (!inputfile.is_open())
        error(1, ERR_FILE_NOT_FOUND);

    _in << inputfile.rdbuf();

    inputfile.close();
}

void Compiler::save(std::string& filename) 
{
  std::ofstream outputfile(std::filesystem::absolute(filename));
  if (!outputfile.is_open())
    error(2, ERR_FILE_NOT_FOUND);

  outputfile << _out.rdbuf();
  outputfile.close();
}

StmtNode::Ptr Compiler::compile()
{
    Scanner scanner(_in);
    ProgramNodeBuilder builder;
    Parser parser(scanner, builder);

    StmtNode::Ptr s = parser.parse();
    out() << s->out().str();
    save(_outfile);
    return s;
}

void Compiler::error(int code, std::string message) 
{
    PLOGE << ANSI_RED << ERR_PREFIX << message << ANSI_RESET << std::endl;
    exit(code);
}


