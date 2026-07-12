#include "compiler_logger.hpp"
#include "compiler_parser.hpp"
#include "compiler_scanner.hpp"
#include "program_node_builder.hpp"
#include <cstdlib>
#include <exception>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <format>

static const std::string ANSI_RESET = "\u001B[0m";
static const std::string ANSI_RED = "\u001B[31m";


// Commandline options
static const std::string OPT_HELP = "-h";
static const std::string OPT_INTERACT = "-i";

// error messages
static const std::string ERR_PREFIX = "Error: ";
static const std::string ERR_INVALID_OPTION = "Not a valid option";
static const std::string ERR_FILE_NOT_FOUND = "File not found, check file path";

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
    //std::cout << s->to_string() << std::endl;
}

std::string timestamp() {
        auto now = std::chrono::system_clock::now();
        auto now_time_t = std::chrono::system_clock::to_time_t(now);
        auto time = std::put_time(localtime(&now_time_t), "%y-%m-%d %h:%m:%s");
        return std::format("{0:%F_%T}", now);
}




int main(int argc, char *argv[])
{
    try {
        std::clog << std::format("{} [{}] {}", timestamp(), ilog::to_string(ilog::LogLevel::INFO), "Hello Logging Stream") << std::endl;
        ilog::lout << "Test logger" << std::endl;
        std::cout << ilog::loggerStream.to_str() << std::endl;

        std::cout << "Hello, Facade!\n";

        std::cout << print_args(argc, argv) << std::endl;

        std::cout << "current dir: " << std::filesystem::current_path() << std::endl;
        std::stringstream filein;
        load_file("./input/in.txt", filein);
        //std::cout << "input file content" << std::endl << filein.str() << std::endl;

        //compile(filein);

        std::cout << "Compile complete!\n";

        //std::cout << usage();

    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
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
    
    /*std::stringstream ssq("{ int x = 10; \nx = 15;\nString s = \"Hello\";\nint y = 5;\nif (x == y)  {\n\tdouble z = 1.5;\n\tx = y + 20 + 5;\n}\n}");*/
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
