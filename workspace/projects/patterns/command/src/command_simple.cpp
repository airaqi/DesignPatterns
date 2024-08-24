//#include "command_simple.hpp"

template <class Receiver>
void CommandSimple<Receiver>::execute()
{
    (_receiver->*_action)();
}
