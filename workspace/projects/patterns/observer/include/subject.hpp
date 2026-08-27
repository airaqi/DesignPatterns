#ifndef __SUBJECT_H__
#define __SUBJECT_H__ 

#include "observer.hpp"
#include <memory>
#include <vector>

class Subject : public std::enable_shared_from_this<Subject>
{
    public:
        using Ptr = std::shared_ptr<Subject>;
        static Ptr create();

    private:
        std::vector<Observer*> _observers;

    public:
        Subject();

    public:
        virtual ~Subject();

        virtual void attach(Observer*);
        virtual void detach(Observer*);
        virtual void notify();
};

#endif /* ifndef __SUBJECT_H__ */
