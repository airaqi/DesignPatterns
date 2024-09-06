#ifndef __SHAPE_TEXT_OBJECT_H__
#define __SHAPE_TEXT_OBJECT_H__ 

#include "point.h"
#include "shape.hpp"
#include "text_view.hpp"

class TextShapeObject : public Shape
{
    public:
        TextShapeObject(TextView* view);

        virtual void boundingBox(Point&, Point&) const override;
        virtual Manipulator * createManipulator() override;
        virtual bool isEmpty() const;

        virtual void setBoundingBox(Point&, Point&) override;

        virtual std::string to_string() override;

        void doSomthing();


    private:
        TextView* _text;
};

#endif /* ifndef __SHAPE_TEXT_OBJECT_H__ */
