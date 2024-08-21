#ifndef __COMMAND_OPEN_H__
#define __COMMAND_OPEN_H__ 

#include "application.hpp"
#include "command.hpp"

class CommandOpen : public Command
{
    public:
        CommandOpen(Application*);
        virtual ~CommandOpen();

        void execute() override;

    protected:
        virtual const char* askUser(char* name, int size);

    private:
        Application* _application;
        char* _response;
};

#endif /* ifndef __COMMAND_OPEN_H__ */
