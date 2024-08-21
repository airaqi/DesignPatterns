#ifndef __COMMAND_MACRO_H__
#define __COMMAND_MACRO_H__ 

#include "command.hpp"
#include "list.h"

class MacroCommand : public Command
{
    public:
        MacroCommand();
        virtual ~MacroCommand();

        virtual void add(Command*);
        virtual void remove(Command*);

        void execute() override;

    private:
        List<Command*>* _cmds;
};

#endif /* ifndef __COMMAND_MACRO_H__ */
