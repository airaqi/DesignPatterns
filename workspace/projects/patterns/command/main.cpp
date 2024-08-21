#include "application.hpp"
#include "command_macro.hpp"
#include "command_open.hpp"
#include "command_paste.hpp"
#include "command_receiver.hpp"
#include "command_simple.hpp"
#include "document.hpp"

int main(int argc, char *argv[])
{
    Application app;
    Document document("test");

    CommandOpen cmd(&app);
    CommandPaste paste(&document);
    CommandReceiver receiver;
    CommandSimple<CommandReceiver> simplecmd(&receiver, &CommandReceiver::action);
    
    CommandMacro cmds;

    cmds.add(&cmd);
    cmds.add(&simplecmd);
    cmds.add(&paste);

    cmds.execute();

    return 0;
}
