#ifndef __CONSTRAINT_SOLVER_H__
#define __CONSTRAINT_SOLVER_H__ 

#include "constraint_solver_memento.hpp"
#include "graphic.hpp"
#include "state_solver.hpp"

class ConstraintSolver
{
    public:
        virtual ~ConstraintSolver();

        static ConstraintSolver* instance();
        static void destroy();

        void solve();
        void addConstraint(Graphic* connection);
        void removeConstraint(Graphic* connection);

        ConstraintSolverMemento* createMemento();
        void setMemento(ConstraintSolverMemento*);

    protected:
        ConstraintSolver();

    private:
        static ConstraintSolver *_instance;
        StateSolver *_state;


};

#endif /* ifndef __CONSTRAINT_SOLVER_H__ */
