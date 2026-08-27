#include "clock_timer.hpp"
#include <chrono>
#include <ctime>
#include <memory>
#include <mutex>
#include <stop_token>
#include <thread>

ClockTimer::ClockTimer(std::chrono::milliseconds interval) : _interval(interval) { start(); }
ClockTimer::ClockTimer(int interval) : ClockTimer(std::chrono::milliseconds(interval)) {}
ClockTimer::~ClockTimer() { stop(); }

ClockTimer::Ptr ClockTimer::create(int interval) { return std::make_shared<ClockTimer>(interval); }
ClockTimer::Ptr ClockTimer::create(std::chrono::milliseconds interval) { return std::make_shared<ClockTimer>(interval); }

void ClockTimer::start()
{
    stop();

    {
        std::lock_guard<std::mutex> lock(_mutex);
        _running = true;
    }

    _timerThread = std::jthread([this](std::stop_token stopToken)
            {
                std::unique_lock<std::mutex> lock(_mutex);
                while(_running && !stopToken.stop_requested())
                {
                    // wait for the interval or until notified to stop
                    _cv.wait_for(lock, _interval, [this, &stopToken] { return !_running || stopToken.stop_requested(); });

                    // execute callback if we woke up due to timeout, not due to stopping
                    if (_running && !stopToken.stop_requested()) tick();
                }
            });
    tick();
}

void ClockTimer::stop() 
{
    {
        std::lock_guard<std::mutex> lock(_mutex);
        if (!_running) return;
        _running = false;
    }

    _cv.notify_all();

    if (_timerThread.joinable()) _timerThread.join();
}

void ClockTimer::tick() 
{
    _ptime = _time;
    _pt = _t;

    _t = std::time(nullptr);
    _time = *localtime(&_t);

    notify();
}

int ClockTimer::hour(bool prev)     { return (prev && _pt != _t) ? _ptime.tm_hour : _time.tm_hour; }
int ClockTimer::minute(bool prev)   { return (prev && _pt != _t) ? _ptime.tm_min : _time.tm_min; }
int ClockTimer::second(bool prev)   { return (prev && _pt != _t) ? _ptime.tm_sec : _time.tm_sec; }

