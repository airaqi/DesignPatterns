#include "subject.hpp"
#include "observer.hpp"
#include <algorithm>
#include <memory>

Subject::Subject() {}
Subject::~Subject() {}

Subject::Ptr Subject::create() { return std::make_shared<Subject>(); }

void Subject::attach(Observer* observer) { _observers.push_back(observer); }
void Subject::detach(Observer* observer) { std::erase(_observers, observer); }

void Subject::notify()
{
    std::for_each(_observers.begin(), _observers.end(), [this](Observer* item) { item->update(shared_from_this()); });

}


