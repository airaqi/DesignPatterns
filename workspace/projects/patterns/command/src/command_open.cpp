#include "command_open.hpp"
#include "document.hpp"
#include <cstring>
#include <iostream>

CommandOpen::CommandOpen(Application* application) : _application(application)
{
}

CommandOpen::~CommandOpen()
{
}

void CommandOpen::execute()
{
    int size = 256;
    char name[size];
    askUser(name, size);

    if (name[0] != 0) 
    {
        Document doc(name);
        _application->addDocument(&doc);
        doc.open();
    }
}

const char* CommandOpen::askUser(char* name, int size)
{
    std::cout << "Name: ";
    std::cin.getline(name, size);
    return name;
}

