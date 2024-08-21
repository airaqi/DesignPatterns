#include "application.hpp"
#include "command_macro.hpp"
#include "command_open.hpp"
#include "command_paste.hpp"
#include "command_receiver.hpp"
#include "command_simple.hpp"
#include "document.hpp"
#include <cstring>

int main(int argc, char *argv[])
{
    Application app;
    char* name = new char[256];
    std::strcpy(name, "test");
    Document document(name);

    CommandOpen open_test(&app);
    open_test.execute();
    Document* newDoc = app.getDocument(0);
    CommandPaste paste1(newDoc);
    CommandPaste paste2(&document);
    CommandReceiver receiver;
    CommandSimple<CommandReceiver> simplecmd(&receiver, &CommandReceiver::action);
    
    CommandMacro cmds;

    cmds.add(&simplecmd);
    cmds.add(&paste1);
    cmds.add(&paste2);
    

    cmds.execute();

    return 0;
}
