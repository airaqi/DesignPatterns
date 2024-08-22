#include "command_macro.hpp"
#include "command.hpp"
#include "list.h"
#include "list_iterator.h"


CommandMacro::CommandMacro() : _cmds(new List<Command*>){}
CommandMacro::~CommandMacro() { delete _cmds; }


void CommandMacro::add(Command* cmd)
{
    _cmds->append(cmd);
}


void CommandMacro::remove(Command* cmd)
{
    _cmds->remove(cmd);
}


void CommandMacro::execute()
{
    ListIterator<Command*> i(_cmds);
    for (i.first(); !i.is_done(); i.next())
        i.currentItem()->execute();
}
