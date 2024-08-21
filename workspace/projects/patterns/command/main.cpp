#include "application.hpp"
#include "command_macro.hpp"
#include "command_open.hpp"
#include "command_receiver.hpp"
#include "command_simple.hpp"

int main(int argc, char *argv[])
{
    Application app;

    CommandOpen cmd(&app);
    CommandReceiver receiver;
    SimpleCommand<CommandReceiver> simplecmd(&receiver, &CommandReceiver::action);
    
    MacroCommand cmds;
    cmds.add(&cmd);
    cmds.add(&simplecmd);

    cmds.execute();

    return 0;
}
