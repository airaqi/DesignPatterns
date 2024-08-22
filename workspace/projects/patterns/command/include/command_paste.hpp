#ifndef __COMMAND_PASTE_H__
#define __COMMAND_PASTE_H__ 

#include "command.hpp"
#include "document.hpp"

class CommandPaste : public Command
{
    public:
        CommandPaste(Document*);
        virtual ~CommandPaste();

        void execute() override;

    private:
        Document* _document;
};

#endif /* ifndef __COMMAND_PASTE_H__ */
