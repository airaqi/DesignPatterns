#ifndef __CLOCKTIMER_H__
#define __CLOCKTIMER_H__ 

#include "subject.hpp"
#include <chrono>
#include <condition_variable>
#include <ctime>
#include <memory>
#include <mutex>
#include <thread>

class ClockTimer : public Subject
{
    private:
        std::chrono::milliseconds _interval;
        std::time_t _t, _pt;
        std::tm _time, _ptime;
        std::jthread _timerThread;
        std::condition_variable _cv;
        std::mutex _mutex;
        bool _running{false};

    public:
        using Ptr = std::shared_ptr<ClockTimer>;
        static Ptr create(int);
        static Ptr create(std::chrono::milliseconds);

        ClockTimer(int);
        ClockTimer(std::chrono::milliseconds interval);
        ClockTimer(const ClockTimer&) = delete;
        ~ClockTimer();
        ClockTimer& operator=(const ClockTimer&) = delete;

        void start();
        void stop();

        virtual int hour(bool=false);
        virtual int minute(bool=false);
        virtual int second(bool=false);

        void tick();
};

#endif /* ifndef __CLOCKTIMER_H__ */
