//#include "command_simple.hpp"

template <class Receiver>
void SimpleCommand<Receiver>::execute()
{
    (_receiver->*_action)();
}
