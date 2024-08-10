#ifndef __COMPOSITION_H__
#define __COMPOSITION_H__ 

#include "compositor.h"
#include "component.h"

class Composition
{
    public: 
        Composition(Compositor* compositor) : _compositor(compositor) {}
        ~Composition();
        void repair();

    private:
        Compositor* _compositor;
        // the list of components
        Component* _components;
        // the number of components
        int _component_count;
        // the composition's line width
        int _line_width;
        // the position of linebreaks in components
        int* _line_breaks;
        // the number of lines.
        int _line_count;
};

#endif /* ifndef __COMPOSITION_H__ */
