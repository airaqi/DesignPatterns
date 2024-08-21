#include "command_open.hpp"
#include "document.hpp"
#include <cstring>
#include <iostream>
#include <string>

CommandOpen::CommandOpen(Application* application) : _application(application)
{
}

CommandOpen::~CommandOpen()
{
}

void CommandOpen::execute()
{
    char name[20] = { 0 };
    askUser(name, std::strlen(name));

    if (name[0] != 0) 
    {
        Document* doc = new Document(name);
        _application->addDocument(doc);
        doc->open();
    }
}

const char* CommandOpen::askUser(char* name, int size)
{
    std::string sname;
    std::cout << "Name: ";
    std::getline(std::cin, sname);
    std::strcpy(name, sname.c_str());
    return name;
}

