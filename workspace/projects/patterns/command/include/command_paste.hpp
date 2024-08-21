#ifndef __COMMAND_PASTE_H__
#define __COMMAND_PASTE_H__ 

#include "command.hpp"
#include "document.hpp"

class PasteCommand : public Command
{
    public:
        PasteCommand(Document*);
        virtual ~PasteCommand();

        void execute() override;

    private:
        Document* _document;
};

#endif /* ifndef __COMMAND_PASTE_H__ */
