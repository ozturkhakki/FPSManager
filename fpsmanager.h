#ifndef FPSMANAGER_H
#define FPSMANAGER_H

#include <chrono>

// It is better to have only one instance of this class
// in the entire program. So, simply put, this is a static
// class

class FPSManager
{
public:
    FPSManager();

    //  Update the time
    static void updateTime();
    
    //  Update the last time that is drawn frame
    static void updateLastFrameTime();
    
    //  Get elapsed time between last time a frame drawn and
    //  current time
    static float getElapsedTime();
    
    //  Get current time 
    static float getTime();
    
    //  Makes calculation according to a second
    //
    //  Lets say you have an object that moves 5
    //  unit a second. If elapsed time is 100 miliseconds
    //  you will get 0.5(0.100 * 5) unit.
    static float makeCalcWithElapsedTime(float someValue);
    
    //  Set frame. This way you will get true if a new frame
    //  should be drawn.
    static void setFPS(unsigned int fps);
    
    //  Return true if a new frame should be drawn.
    static bool shouldDrawNewFrame();

private:
    static float m_current;
    static float m_lastFrame;
    static unsigned int m_FPS{1000};

};


#endif // FPSMANAGER_H
