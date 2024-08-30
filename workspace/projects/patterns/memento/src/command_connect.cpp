#include "command_connect.hpp"
#include "constraint_solver.hpp"
#include "graphic_connect.hpp"


CommandConnect::CommandConnect(GraphicCanvas* context, Graphic* start, Graphic* end) :
    _context(context), _start(start), _end(end), _target(nullptr), _state(nullptr) {}

CommandConnect::~CommandConnect()
{
    if (_state) delete _state;
    _context = nullptr;
    _start = nullptr;
    _end = nullptr;
    _target = nullptr;

}

void CommandConnect::execute()
{
    ConstraintSolver *solver = ConstraintSolver::instance();
    _state = solver->createMemento();
    _target = new GraphicConnect(_start, _end);
    _context->add(_target);
    solver->solve();
}

void CommandConnect::unexecute()
{
    if (!_state) return;
    
    ConstraintSolver *solver = ConstraintSolver::instance();
    _context->remove(_target);
    solver->setMemento(_state);
    _state = nullptr;
    solver->solve();
    delete _target;
    _target = nullptr;
    solver = nullptr;
}

GraphicCanvas* CommandConnect::context()
{
    return _context;
}

Graphic* CommandConnect::target()
{
    return _target;
}

