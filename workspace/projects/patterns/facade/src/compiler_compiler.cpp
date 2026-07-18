#include "compiler_compiler.hpp"
#include "compiler_code_generator.hpp"
#include "compiler_parser.hpp"
#include "compiler_scanner.hpp"
#include "plog/Log.h"
#include "program_node_builder.hpp"
#include <iostream>
#include <istream>
#include <memory>
#include <ostream>
#include <stdexcept>
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

std::shared_ptr<Compiler> Compiler::_instance = nullptr;


Compiler::Compiler(std::istream& in, std::ostream& out) : _in(in), _out(out) {}

Compiler::Ptr Compiler::create(std::istream& in, std::ostream& out) 
{
  return std::make_shared<Compiler>(in, out);
}

std::shared_ptr<Compiler> Compiler::get_instance() 
{
    if (_instance)
      return _instance;
    throw std::runtime_error("Uninistialized compiler");
}

std::shared_ptr<Compiler> Compiler::get_instance(std::istream& in, std::ostream& out) 
{
  if (!_instance) 
    _instance = Compiler::create(in, out);
  return _instance;
}

std::istream& Compiler::get_in() const { return _in; }
std::ostream& Compiler::get_out() const { return _out; }


StmtNode::Ptr Compiler::compile()
{
    Scanner scanner(_in);
    ProgramNodeBuilder builder;
    Parser parser(scanner, builder);

    StmtNode::Ptr s = parser.parse();
    get_out() << s->out().str();
    return s;
}

void Compiler::error(int code, std::string message) 
{
    PLOGE << ANSI_RED << ERR_PREFIX << message << ANSI_RESET << std::endl;
    exit(code);
}


