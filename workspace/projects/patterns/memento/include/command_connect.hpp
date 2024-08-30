#ifndef __COMMAND_CONNECT_H__
#define __COMMAND_CONNECT_H__ 

#include "command.hpp"
#include "constraint_solver_memento.hpp"
#include "graphic.hpp"
#include "graphic_canvas.hpp"

class CommandConnect : public Command
{
    public:
        CommandConnect(GraphicCanvas*, Graphic*, Graphic*);
        virtual ~CommandConnect();

        virtual void execute() override;
        virtual void unexecute() override;

        virtual GraphicCanvas* context();
        virtual Graphic* target();

    private:
        GraphicCanvas *_context;
        Graphic *_start, *_end;
        Graphic *_target;
        ConstraintSolverMemento *_state;
};

#endif /* ifndef __COMMAND_CONNECT_H__ */
