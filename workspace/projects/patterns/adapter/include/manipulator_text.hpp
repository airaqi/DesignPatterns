#ifndef __MANIPULATOR_TEXT_H__
#define __MANIPULATOR_TEXT_H__ 

#include "manipulator.hpp"

class TextManipulator : public Manipulator
{
    public:
        TextManipulator(Shape* shape);

        void move(const Point &) override;
};

#endif /* ifndef __MANIPULATOR_TEXT_H__ */
