#ifndef __CONSTRAINT_SOLVER_MEMENTO_H__
#define __CONSTRAINT_SOLVER_MEMENTO_H__ 

#include "state_solver.hpp"

class ConstraintSolverMemento 
{
    public:
        virtual ~ConstraintSolverMemento() { delete _state; }

    private:
        ConstraintSolverMemento() : _state(new StateSolver) {}
        ConstraintSolverMemento(StateSolver *state) : _state(new StateSolver(state)) {}
        friend class ConstraintSolver;

        StateSolver *_state;
};

#endif /* ifndef __CONSTRAINT_SOLVER_MEMENTO_H__ */
