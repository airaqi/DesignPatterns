#ifndef __COMMAND_SIMPLE_H__
#define __COMMAND_SIMPLE_H__ 

#include "command.hpp"
template <class Receiver>
class CommandSimple : public Command
{
    public:
        typedef void (Receiver::* Action)();

        CommandSimple(Receiver* r, Action a) : _receiver(r), _action(a) {}
        virtual ~CommandSimple() {}

        void execute() override;

    private:
        Action _action;
        Receiver* _receiver;
};

#include "command_simple.cpp"

#endif /* ifndef __COMMAND_SIMPLE_H__ */
