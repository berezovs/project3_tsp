#include <chrono>
#include "Timer.hpp"

Timer::Timer()
{
}

void Timer::startTimer()
{
    start = std::chrono::system_clock::now();
}

void Timer::stopTimer()
{
    stop = std::chrono::system_clock::now();
}

int Timer::getElapsedTimeInMilliseconds()
{
    std::chrono::duration<double> diff = stop - start;
    return diff.count() * 1000;
}
