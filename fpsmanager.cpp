#include "fpsmanager.h"

float FPSManager::m_lastFrame;
float FPSManager::m_previousFrame;
unsigned int FPSManager::m_FPS;
float FPSManager::m_whenGameStarted;

FPSManager::FPSManager()
{
    m_lastFrame = 0f;
    m_previousFrame = 0f;
    m_FPS = 1000;
    m_whenGameStarted = std::chrono::duration_cast<
            std::chrono::duration<float, std::milli>>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}

void FPSManager::updateLastFrameTime()
{
    m_previousFrame = m_lastFrame;
    
    m_lastFrame = std::chrono::duration_cast<
            std::chrono::duration<float, std::milli>>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}

float FPSManager::getElapsedTime()
{
    return m_lastFrame - m_previousFrame;
}

float FPSManager::getTime()
{
    return m_lastFrame;
}

float FPSManager::makeCalcWithElapsedTime(float someValue)
{
    return (this->getElapsedTime() / 1000) * someValue;
}

void FPSManager::setFPS(unsigned int fps)
{
    m_FPS = fps;
}

bool FPSManager::shouldDrawNewFrame()
{
    if((1000 / m_FPS) >= getElapsedTime()){
        updateLastFrameTime();
        return true;
    } else {
        return false;
    }
}
