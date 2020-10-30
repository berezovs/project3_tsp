#ifndef TIMER_H
#define TIMER_H
#include <chrono>
#include <string>
class Timer
{
public:
    Timer();
    void startTimer();
    void stopTimer();
    int getElapsedTimeInMilliseconds();
    std::string getFormattedTime();

private:
    std::chrono::time_point<std::chrono::system_clock> start, stop;
};
#endif
