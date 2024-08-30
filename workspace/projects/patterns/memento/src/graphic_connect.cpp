#include "graphic_connect.hpp"
#include "constraint_solver.hpp"
#include "graphic_line.hpp"
#include <cstring>
#include <iostream>

GraphicConnect::GraphicConnect(Graphic* start, Graphic* end) : _start(start), _end(end), _line(nullptr) 
{
    ConstraintSolver* solver = ConstraintSolver::instance();
    solver->addConstraint(this);
    solver->solve();
    solver = nullptr;
}

GraphicConnect::~GraphicConnect() 
{
    if (_line) 
    {
        delete _line;
        _line = nullptr;
    }
}

void GraphicConnect::move(Point p)
{
    _start->move(p);
    _end->move(p);
}

void GraphicConnect::display()
{
}

void GraphicConnect::print(const char* prefix)
{
    std::cout << prefix << "[Connect ";
    _line->print(prefix);
    std::cout << prefix << "]\n";
}

bool GraphicConnect::contains(Point &p)
{
    return _line->contains(p);
}

Point GraphicConnect::center()
{
    if (_line)
        delete _line;
    _line = new GraphicLine(_start->center(), _end->center());
    _center = _line->center();
    return _center;
}
