#ifndef __OBSERVER_H__
#define __OBSERVER_H__ 

#include <memory>
class Subject;

class Observer
{
    public:
        using Ptr = std::shared_ptr<Observer>;

        virtual ~Observer();
        virtual void update(std::shared_ptr<Subject>) = 0;

    public:
        Observer();
};

#endif /* ifndef __OBSERVER_H__ */
