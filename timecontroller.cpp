#include "timecontroller.h"

TimeController::TimeController()
{
}

void TimeController::updateTime()
{
    // Updating time, last time becomes previous
    // and last time is updated
    mTimePrevious = mTimeLast;
    mTimeLast = std::chrono::high_resolution_clock::now();
}

void TimeController::displayedAFrameJustNow()
{
    mFrameTimeLast = std::chrono::high_resolution_clock::now();
}

std::chrono::milliseconds TimeController::getElapsedTimeAsMilliseconds()
{
    // Substract two time points while converting them to milliseconds
    return std::chrono::duration_cast<std::chrono::milliseconds>(mTimeLast.time_since_epoch()) -
            std::chrono::duration_cast<std::chrono::milliseconds>(mTimePrevious.time_since_epoch());
}

double TimeController::getElapsedTime()
{
    return getElapsedTimeAsMilliseconds().count();
}

std::chrono::milliseconds TimeController::getElapsedTimeSinceLastFrameAsMilliseconds()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(mTimeLast.time_since_epoch()) -
            std::chrono::duration_cast<std::chrono::milliseconds>(mFrameTimeLast.time_since_epoch());
}

double TimeController::getElapsedTimeSinceLastFrame()
{
    return getElapsedTimeAsMilliseconds().count();
}

double TimeController::makeCalcWithElapsedTime(double someValue)
{
    // Calculations are based on SECONDS
    //
    // Double is used for precision and to
    // prevent data loss at some calculations
    //
    // Object moves 10 unit per second,
    // 150 milliseconds has passed,
    // then our object should move 1.5
    // which means function will return 1.5
    return (someValue * getElapsedTime()) / 1000.d;
}
