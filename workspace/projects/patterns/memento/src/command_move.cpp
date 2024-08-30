#include "command_move.hpp"
#include "constraint_solver.hpp"

CommandMove::CommandMove(Graphic* target, const Point& delta) : _target(target), _delta(delta), _state(nullptr) {}

CommandMove::~CommandMove() 
{
    if (_state) delete _state;
    _state = nullptr;
}

void CommandMove::execute()
{
    ConstraintSolver* solver = ConstraintSolver::instance();
    _state = solver->createMemento();
    _target->move(_delta);
    solver->solve();
}

void CommandMove::unexecute()
{
    if (!_state) return;

    ConstraintSolver* solver = ConstraintSolver::instance();
    _target->move(-_delta);
    solver->setMemento(_state);
    solver->solve();
    _state = nullptr;
}

