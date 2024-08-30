#ifndef __COMMAND_H__
#define __COMMAND_H__ 

class Command 
{
    public:
        Command() {}
        virtual ~Command() {}

        virtual void execute() = 0;
        virtual void unexecute() = 0;
};

#endif /* ifndef __COMMAND_H__ */
