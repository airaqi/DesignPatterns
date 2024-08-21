#include "command_macro.hpp"
#include "command.hpp"
#include "list.h"
#include "list_iterator.h"


MacroCommand::MacroCommand() : _cmds(new List<Command*>){}
MacroCommand::~MacroCommand() { delete _cmds; }


void MacroCommand::add(Command* cmd)
{
    _cmds->append(cmd);
}


void MacroCommand::remove(Command* cmd)
{
    _cmds->remove(cmd);
}


void MacroCommand::execute()
{
    ListIterator<Command*> i(_cmds);
    for (i.first(); !i.is_done(); i.next())
        i.currentItem()->execute();
}
