#ifndef __COMMAND_CREATE_H__
#define __COMMAND_CREATE_H__ 

#include "command.hpp"
#include "constraint_solver_memento.hpp"
#include "graphic.hpp"
#include "graphic_canvas.hpp"
#include "rect.h"

class CommandCreateRectangle : public Command
{
    public:
        CommandCreateRectangle(GraphicCanvas*, Rect);
        CommandCreateRectangle(GraphicCanvas*, Point, Point);
        CommandCreateRectangle(GraphicCanvas*, Coord, Coord, Coord, Coord);
        virtual ~CommandCreateRectangle();

        virtual void execute() override;
        virtual void unexecute() override;

        virtual Graphic* target();
        virtual GraphicCanvas* context();

    private:
        Rect _rect;
        GraphicCanvas* _context;
        Graphic* _target;
        ConstraintSolverMemento* _state;
};

#endif /* ifndef __COMMAND_CREATE_H__ */
