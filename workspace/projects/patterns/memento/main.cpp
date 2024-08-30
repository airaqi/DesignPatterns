#include "command_connect.hpp"
#include "command_create_rectangle.hpp"
#include "command_move.hpp"
#include "constraint_solver.hpp"
#include "graphic_canvas.hpp"
#include "graphic_connect.hpp"
#include "graphic_line.hpp"
#include "graphic_rectangle.hpp"
#include "point.h"
#include "rect.h"
#include <iostream>

int main(int argc, char *argv[])
{
    std::cout << "Hello, Memnto!\n";
    
    GraphicLine *line01 = new GraphicLine(10, 10, 20, 20);
    //GraphicRectangle *rect01 = new GraphicRectangle(Rect(30, 30, 50, 20));
    //GraphicRectangle *rect02 = new GraphicRectangle(100, 100, 40, 20);
    //GraphicConnect *con01 = new GraphicConnect(rect01, rect02);
    GraphicCanvas cnvs(0, 0, 500, 300);

    cnvs.add(line01);
    //cnvs.add(rect01);
    //cnvs.add(rect02);
    //cnvs.add(con01);
    
    //line01->print();
    //rect01->print();

    //rect01->move(Point(10, 10));
    //rect01->print();

    cnvs.print();

    CommandCreateRectangle recCmd01(&cnvs, Rect(30, 30, 50, 20));
    CommandCreateRectangle recCmd02(&cnvs, Rect(100, 100, 40, 20));
    CommandCreateRectangle recCmd03(&cnvs, Rect(60, 60, 30, 20));

    std::cout << "execute create rectangle\n";

    recCmd01.execute();
    recCmd02.execute();
    recCmd03.execute();
    cnvs.print();

    std::cout << "execute connect\n";

    CommandConnect conCmd01(&cnvs, recCmd01.target(), recCmd02.target());
    conCmd01.execute();

    cnvs.print();

    std::cout << "execute move rectangle\n";

    CommandMove movCmd(recCmd01.target(), Point(10, 10));
    movCmd.execute();
    cnvs.print();

    std::cout << "unexecute move rectangle\n";

    movCmd.unexecute();
    cnvs.print();

    std::cout << "unexecute create rectangle\n";

    recCmd03.unexecute();
    cnvs.print();

    // TODO move to application class
    ConstraintSolver::destroy();
    
    return 0;
}
