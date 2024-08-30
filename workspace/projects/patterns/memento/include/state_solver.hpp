#ifndef __STATE_SOLVER_H__
#define __STATE_SOLVER_H__ 

#include "graphic.hpp"
#include "list.h"
#include "state.hpp"

class ConstraintSolver;

class StateSolver : public State
{
    public:
        StateSolver() : _constraints(new List<Graphic*>()) {}
        StateSolver(StateSolver *state) : _constraints(new List<Graphic*>(*state->_constraints)) {}
        virtual ~StateSolver() { _constraints->remove_all(); delete _constraints; }

    private:
        friend class ConstraintSolver;
        List<Graphic*>* _constraints;
};

#endif /* ifndef __STATE_SOLVER_H__ */
