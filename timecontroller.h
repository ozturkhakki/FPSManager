#ifndef TIMECONTROLLER_H
#define TIMECONTROLLER_H

// A class that is made to ease time calculations. Can
// be applied to SFML, Allegro and SDL.

#include <chrono>

class TimeController
{
public:
    TimeController();

    // Use this function to update time
    void updateTime();

    // To store the last time we rendered a frame
    // in case if you need
    void updateLastFrameTime();

    // Get elapsed time as milliseconds
    std::chrono::milliseconds getElapsedTimeAsMilliseconds();

    // Gets the elapsed time as double if you
    // want to do some things with it
    double getElapsedTime();

    // Gets the elapsed time since you last
    // rendered a frame as milliseconds
    std::chrono::milliseconds getElapsedTimeSinceLastFrameAsMilliseconds();

    // Gets the elapsed time since you last
    // rendered a frame as double
    double getElapsedTimeSinceLastFrame();

    // Easy way to make calculations with elapsed time
    double makeCalcWithElapsedTime(double someValue);

private:
    // To store the last two times, we have two variables
    //
    // Initializing them immediately
    std::chrono::high_resolution_clock::time_point mTimeLast{std::chrono::high_resolution_clock::now()};
    std::chrono::high_resolution_clock::time_point mTimePrevious{mTimeLast};

    // Also adding one more variable to store last time
    // we rendered a frame.
    std::chrono::high_resolution_clock::time_point mFrameTimeLast{mTimeLast};

    // To increase performance, other time variables' values
    // are assigned mTimeLast's value
};

#endif // TIMECONTROLLER_H
