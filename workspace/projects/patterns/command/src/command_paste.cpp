#include "command_paste.hpp"


PasteCommand::PasteCommand(Document* doc) : _document(doc) {}
PasteCommand::~PasteCommand() {}


void PasteCommand::execute()
{
    _document->paste();
}


