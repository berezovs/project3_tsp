/***************************************************************
  Student Name:Serghei Berezovschi
  File Name: Timer.cpp
  Assignment number:Project 3-DS&AII

 
***************************************************************/
#include <chrono>
#include "Timer.hpp"

Timer::Timer()
{
}
//starts timer
void Timer::startTimer()
{
    start = std::chrono::system_clock::now();
}
//stops timer
void Timer::stopTimer()
{
    stop = std::chrono::system_clock::now();
}

//returns an integer representing the number of elapsed milliseconds
int Timer::getElapsedTimeInMilliseconds()
{
    std::chrono::duration<double> diff = stop - start;
    return diff.count() * 1000;
}

//returns a string representing the  number of milliseconds, seconds or minutes measured
std::string Timer::getFormattedTime()
{
    int elapsedTime = this->getElapsedTimeInMilliseconds();

    //if elapsed time is under a second
    if (elapsedTime < 1000)
    {
        return std::to_string(elapsedTime) + " milliseconds";
    }
    //if elapsed time is under a minute
    else if (elapsedTime < (1000 * 60))
    {
        return std::to_string(elapsedTime / 1000) + " seconds";
    }
    int seconds = elapsedTime / 1000;
    int minutes = seconds / 60;
    seconds = seconds % 60;

    return std::to_string(minutes) + " minutes and " + std::to_string(seconds) + " seconds";
}
