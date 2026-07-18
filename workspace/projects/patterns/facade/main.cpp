#include "compiler_compiler.hpp"
#include "compiler_parser.hpp"
#include "compiler_scanner.hpp"
#include "plog/Appenders/ConsoleAppender.h"
#include "plog/Appenders/RollingFileAppender.h"
#include "plog/Logger.h"
#include "plog/Severity.h"
#include "program_node_builder.hpp"
#include <bits/getopt_core.h>
#include <cstdlib>
#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <format>
#include <plog/Log.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Formatters/MessageOnlyFormatter.h>
#include <plog/Initializers/ConsoleInitializer.h>
#include <plog/Initializers/RollingFileInitializer.h>
#include <getopt.h>
#include <vector>

static const std::string ANSI_RESET = "\u001B[0m";
static const std::string ANSI_RED = "\u001B[31m";


// error messages
static const std::string ERR_PREFIX = "Error: ";
static const std::string ERR_INVALID_OPTION = "Not a valid option";
static const std::string ERR_FILE_NOT_FOUND = "File not found, check file path";

struct longoption : public option {
  std::string description;
  std::string param_name;
};

struct longoption long_options[] = 
{
  { "source-file", required_argument, nullptr, 'f', "Source file", "src-file" },
  { "destination-file", required_argument, nullptr, 'd', "Destination file", "dest-file" },
  { "verbose", no_argument, nullptr, 'v', "Go Verbose", "" },
  { "log-level", required_argument, nullptr, 'l', "Set log level", "level" },
  { "help", no_argument, nullptr, 'h', "Print help and Exit", "" }
};

std::string get_short_options() {
  std::string short_options;
  for (int i = 0; i < std::size(long_options); i++)
    short_options.append(
        std::format("{}{}", 
          static_cast<char>(long_options[i].val),
          (long_options[i].has_arg ? ":" : "")
          ));
  return short_options;
}

void error(int code, std::string message)
{
    std::cout << ANSI_RED << ERR_PREFIX << message << ANSI_RESET << std::endl;
    exit(code);
}

int find_arg(const std::string option, int argc, char *argv[]) {
    for(int i = 0; i < argc; i++)
        if (option == argv[i])
            return i;
    return -1;
}

std::stringstream& load_file(std::string filename, std::stringstream& stream)
{
    std::ifstream inputfile(filename);
    if (!inputfile.is_open())
        error(1, ERR_FILE_NOT_FOUND);

    stream << inputfile.rdbuf();

    inputfile.close();

    return stream;
}

std::string usage()
{
    std::string syntaxformat = "{}\n\t{}\n";
    std::string optionsFormat = "\t{:<15}{:<35}{}\n";
    std::stringstream options, parameters;

    for (int i = 0; i < std::size(long_options); i++)
    {
        std::string shortOption = std::format("-{}{}", 
            static_cast<char>(long_options[i].val), 
            (long_options[i].has_arg ? std::format(" <{}>", long_options[i].param_name) : ""));
        std::string longOption = std::format("--{}{}", 
            long_options[i].name, 
            (long_options[i].has_arg ? std::format(" <{}>", long_options[i].param_name) : ""));
        options << std::vformat(optionsFormat,  std::make_format_args(shortOption, longOption, long_options[i].description));
        parameters << std::format("[{}]", shortOption);
    }
 
    std::string synopsis = std::vformat(syntaxformat, std::make_format_args("Synopsis:", "Compiles input file"));
    std::string param_str = std::format("facade_app {}", parameters.str());
    std::string syntax = std::vformat(syntaxformat, std::make_format_args("Syntax:", param_str));
   
    std::stringstream sout;
    sout << synopsis << std::endl << syntax << std::endl << options.str() << std::endl;
    return sout.str();
}

std::string print_args(int argc, char *argv[])
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

void compile(std::stringstream& stream)
{
    Scanner scanner(stream);
    ProgramNodeBuilder builder;
    Parser parser(scanner, builder);
    StmtNode::Ptr s = parser.parse();
    std::cout << std::endl;
}

plog::Severity get_plog_level(std::string level_str) 
{
  plog::Severity level = plog::info;
  if (level_str == "verbose") level = plog::verbose;
  else if (level_str == "debug") level = plog::debug;
  else if (level_str == "warning") level = plog::warning;
  else if (level_str == "info") level = plog::info;
  else if (level_str == "errpr") level = plog::error;
  else if (level_str == "fatal") level = plog::fatal;
  else if (level_str == "none") level = plog::none;
  return level;
}

enum { STDOUT = 0, STDERR = 1 };

void initLogger() 
{
    plog::init<plog::TxtFormatter>(plog::info, plog::streamStdOut);
    plog::init<plog::TxtFormatter, STDERR>(plog::verbose, plog::streamStdErr);
}


int main(int argc, char *argv[]) {
  try {
    initLogger();

    PLOGI << "Hello, Facade!";
    PLOGD << print_args(argc, argv);
    PLOGD << "current dir: " << std::filesystem::current_path();

    std::string default_filepath = "./input/in.txt", filepath = default_filepath;
    std::string default_destpath = "./output/output.txt", destpath = default_destpath;
    std::string short_options = get_short_options();;
    int opt;
    int option_index = 0;

    PLOGD << "short_options: " << short_options;

    while ((opt = getopt_long(argc, argv, short_options.c_str(), static_cast<struct option*>(long_options), &option_index)) != -1)
    {
      switch(opt)
      {
        case 'f':
          PLOGI << "source-file: " << optarg;
          filepath = std::format("{}", optarg);
          if (!std::filesystem::exists(filepath)) {
            PLOGI << "ERROR: file: '" << filepath << "' doesn't exist!\n";
            return -1;
          }
          break;
        case 'd':
          destpath = std::format("{}", optarg);
          if (!std::filesystem::exists(destpath))
          {
            PLOGI << "ERROR: file: '" << destpath << "' doesn't exist!\n";
          }
          break;
        case 'v':
          plog::get()->setMaxSeverity(plog::verbose);
          break;
        case 'l':
          plog::get()->setMaxSeverity(get_plog_level(optarg));
          break;
        case 'h':
        case '?':
          std::cout << usage() << "\n";
          return 0;
        default:
          break;
      }
    }

    std::stringstream filein;

    load_file(filepath, filein);
    PLOGI << "----- input file start: ----" << std::endl << filein.str();
    PLOGI << "---- input file end ----" << std::endl;

    std::ofstream fileout(destpath);

    std::shared_ptr<Compiler> compiler = Compiler::get_instance(filein, fileout);
    compiler->compile();
    // compile(filein);

    PLOGI << "Compile complete!";

    // std::cout << usage();

  } catch (const std::runtime_error &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 1;
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
    return 2;
  } catch (...) {
    std::cerr << "Error: unknown exception." << std::endl;
    return 3;
  }

  /*    std::string j = "int a = 10;\n"*/
  /*"String test = \"Hello\";\n"*/
  /*"if(a == 1 && x != 79) {\n"*/
  /*"\ttest = 0;\n"*/
  /*"\ty=5.4;\n"*/
  /*"\tname_1=100;\n"*/
  /*"}";*/
  /*std::string p = "a = 10\n"*/
  /*"test = \"Hello\"\n"*/
  /*"if a == 1 and x != 79:\n"*/
  /*"\ttest = 0\n"*/
  /*"\ty = 5.4\n"*/
  /*"\tname_1 = 'Me'"*/
  /*"\n";*/

  /*std::cout << "\nJava: \n" << j << "\n"; */

  /*std::stringstream sj(j);*/
  /*//TokenStream jin(sj);*/
  /*TagJv jsym;*/
  /*Scanner jscan(jsym, sj);*/

  /*while (!jscan.eof())*/
  /*{*/
  /*//Token t = jin.get();*/
  /*Token t = jscan.scan();*/
  /*std::cout << t << "\n";*/
  /*}*/

  /*std::cout << "\nPython: \n" << p << "\n";*/

  /*std::stringstream sp(p);*/
  /*//TokenStream pin(sp);*/
  /*TagPy psym;*/
  /*Scanner pscan(psym, sp);*/

  /*while (!pscan.eof())*/
  /*{*/
  /*//Token t = pin.get();*/
  /*Token t = pscan.scan();*/
  /*std::cout << t << "\n";*/
  /*}*/

  /*std::cout << "\nParser: \n\n";*/

  /*std::stringstream ssq("{ int x = 10; \nx = 15;\nString s = \"Hello\";\nint y
   * = 5;\nif (x == y)  {\n\tdouble z = 1.5;\n\tx = y + 20 + 5;\n}\n}");*/
  /*std::stringstream ssp("{ int x = 10; x = 15; }");*/
  /*std::stringstream ssm("{ int x = 10; }");*/
  /*std::stringstream sss("{ int x = 10; String s = \"Hi There\"; }");*/

  /*std::stringstream sin(ssq.str());*/

  /*std::cout << sin.str() << "\n\n";*/
  /*Scanner scanner(jsym, sin);*/
  /*ProgramNodeBuilder builder;*/
  /*ParserJava parser(scanner, builder);*/
  /*parser.parse(builder.getRootNode());*/

  /*std::cout */
  /*<< sin.str() << "\n" */
  /*<< *builder.getRootNode() << "\n";*/

  return 0;
}
