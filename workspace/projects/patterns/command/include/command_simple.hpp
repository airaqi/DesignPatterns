#ifndef __COMMAND_SIMPLE_H__
#define __COMMAND_SIMPLE_H__ 

#include "command.hpp"
template <class Receiver>
class SimpleCommand : public Command
{
    public:
        typedef void (Receiver::* Action)();

        SimpleCommand(Receiver* r, Action a) : _receiver(r), _action(a) {}
        virtual ~SimpleCommand() {}

        void execute() override;

    private:
        Action _action;
        Receiver* _receiver;
};

#include "command_simple.cpp"

#endif /* ifndef __COMMAND_SIMPLE_H__ */
