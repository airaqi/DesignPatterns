#include "constraint_solver.hpp"
#include "constraint_solver_memento.hpp"
#include "graphic.hpp"
#include "iterator.h"
#include "state_solver.hpp"

ConstraintSolver* ConstraintSolver::_instance = nullptr;

ConstraintSolver::ConstraintSolver() : _state(new StateSolver())  {}

ConstraintSolver::~ConstraintSolver() 
{
    delete _state;
    _state = nullptr;
}

ConstraintSolver* ConstraintSolver::instance() 
{
    if (!_instance)
        _instance = new ConstraintSolver();
    return _instance;
}

void ConstraintSolver::destroy()
{
    if (_instance)
    {
        delete _instance;
        _instance = nullptr;
    }
}

void ConstraintSolver::addConstraint(Graphic* connection)
{
    _state->_constraints->append(connection);
}

void ConstraintSolver::removeConstraint(Graphic* connection)
{
    _state->_constraints->remove(connection);
}

ConstraintSolverMemento* ConstraintSolver::createMemento()
{
    return new ConstraintSolverMemento(_state);
}

void ConstraintSolver::setMemento(ConstraintSolverMemento* memento)
{
    if (_state)
        delete _state;
    _state = new StateSolver(memento->_state);
    delete memento;
}

void ConstraintSolver::solve()
{
    Iterator<Graphic*>& i = _state->_constraints->iterator();
    for (i.first(); !i.is_done(); i.next())
        i.currentItem()->center();
}



