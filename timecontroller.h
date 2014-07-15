#ifndef FPSMANAGER_H
#define FPSMANAGER_H

#include <chrono>

class FPSManager
{
public:
    FPSManager();

    //  Update the time
    void updateTime();
    //  Update the last time that is drawn frame
    void updateLastFrameTime();
    //  Get elapsed time between last time a frame drawn and
    //  current time
    float getElapsedTime();
    //  Makes calculation according to a second
    //
    //  Lets say you have an object that moves 5
    //  unit a second. If elapsed time is 100 miliseconds
    //  you will get 0.5(0.100 * 5) unit.
    float makeCalcWithElapsedTime(float someValue);
    //  Set frame. This way you will get true if a new frame
    //  should be drawn.
    void setFPS(unsigned int fps);
    //  Return true if a new frame should be drawn.
    bool shouldDrawNewFrame();

private:
    float m_current;
    float m_lastFrame;
    unsigned int m_FPS{1000};

};


#endif // FPSMANAGER_H
