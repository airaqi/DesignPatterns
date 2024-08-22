#ifndef __COMMAND_RECEIVER_H__
#define __COMMAND_RECEIVER_H__ 

#include <iostream>
class CommandReceiver 
{
    public:
        CommandReceiver() {}
        virtual ~CommandReceiver() {}

        virtual void action() { std::cout << "Receiver action executed!\n"; }
};

#endif /* ifndef __COMMAND_RECEIVER_H__ */
