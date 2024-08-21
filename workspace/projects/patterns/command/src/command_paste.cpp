#include "command_paste.hpp"


CommandPaste::CommandPaste(Document* doc) : _document(doc) {}
CommandPaste::~CommandPaste() {}


void CommandPaste::execute()
{
    _document->paste();
}


