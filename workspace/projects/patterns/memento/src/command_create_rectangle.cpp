#include "command_create_rectangle.hpp"
#include "constraint_solver.hpp"
#include "graphic_canvas.hpp"
#include "graphic_rectangle.hpp"


CommandCreateRectangle::CommandCreateRectangle(GraphicCanvas* context, Rect rect) : 
    _context(context), _rect(rect), _state(nullptr), _target(nullptr) {}

CommandCreateRectangle::CommandCreateRectangle(GraphicCanvas* context, Point p1, Point p2) : 
    _context(context), _rect(p1, p2), _state(nullptr), _target(nullptr) {}

CommandCreateRectangle::CommandCreateRectangle(GraphicCanvas* context, Coord x, Coord y, Coord w, Coord h) : 
    _context(context), _rect(x, y, w, h), _state(nullptr), _target(nullptr) {}

CommandCreateRectangle::~CommandCreateRectangle() 
{
    if (_state) delete _state;
    _target = nullptr;
    _state = nullptr;
}


void CommandCreateRectangle::execute()
{
    ConstraintSolver *solver = ConstraintSolver::instance();
    _state = solver->createMemento();
    _target = new GraphicRectangle(_rect);
    _context->add(_target);
    solver->solve();
}

void CommandCreateRectangle::unexecute()
{
    if (!_state) return;

    ConstraintSolver *solver = ConstraintSolver::instance();
    _context->remove(_target);
    solver->setMemento(_state);
    solver->solve();
    _context->remove(_target);
    delete _target;
    _target = nullptr;
    _state = nullptr;
}

Graphic* CommandCreateRectangle::target()
{
    return _target;
}

GraphicCanvas* CommandCreateRectangle::context()
{
    return _context;
}
