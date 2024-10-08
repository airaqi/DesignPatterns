#ifndef __COMMAND_H__
#define __COMMAND_H__ 

class Command 
{
    public:
        virtual ~Command() {}

        virtual void execute() = 0;
    protected:
        Command() {}
};

#endif /* ifndef __COMMAND_H__ */
