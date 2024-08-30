#ifndef __COMMAND_MOVE_H__
#define __COMMAND_MOVE_H__ 

#include "command.hpp"
#include "constraint_solver_memento.hpp"
#include "graphic.hpp"
#include "point.h"

class CommandMove : public Command
{
    public:
        CommandMove(Graphic* target, const Point& delta);
        virtual ~CommandMove();

        void execute();
        void unexecute();

    private:
        ConstraintSolverMemento* _state;
        Point _delta;
        Graphic* _target;
};
#endif /* ifndef __COMMAND_MOVE_H__ */
