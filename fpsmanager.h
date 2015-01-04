#ifndef FPSMANAGER_H
#define FPSMANAGER_H

#include <chrono>

// It is better to have only one instance of this class
// in the entire program. So, simply put, this is a static
// class

class FPSManager
{
public:
    // Initialize class variables
    //
    // Used without it class will cause runtime errors
    static void Initialize(unsigned int FPS);
    
    //  Get elapsed time between last frame drawn time
    //  and previous time a frame drawn
    static float getElapsedTime();
    
    //  Get time when last frame drawn
    static float getTime();
    
    //  Makes calculation according to a second
    //
    //  Lets say you have an object that moves 5
    //  units a second. If elapsed time is 100 miliseconds
    //  you will get 0.5(0.100 * 5) unit.
    static float makeCalcWithElapsedTime(float someValue);
    
    //  Return true if a new frame should be drawn.
    static bool shouldDrawNewFrame();

private:
    //  Update the last time, a frame is drawn
    //
    //  NOTE: It is no longer needed to call it from outside
    //  shouldDrawNewFrame() will call it automaticly if
    //  a new frame should be drawn
    static void updateLastFrameTime();

    // Don't ask, name says it
    static float timePassedSinceLastFrame();

    // Get time passed since Epoch
    static float getNow();

private:
    static float m_lastFrame;
    static float m_previousFrame;
    static unsigned int m_FPSTime;
    static float m_whenGameStarted;

};


#endif // FPSMANAGER_H
