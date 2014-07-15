#include "fpsmanager.h"

void FPSManager::updateTime()
{
    m_current = std::chrono::duration_cast<
            std::chrono::duration<float, std::milli>>(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}

void FPSManager::updateLastFrameTime()
{
    m_lastFrame = m_current;
}

float FPSManager::getElapsedTime()
{
    return m_current - m_lastFrame;
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
    return (1000 / m_FPS) >= getElapsedTime();
}
