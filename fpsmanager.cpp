#include "fpsmanager.h"
#include <iostream>

float FPSManager::m_lastFrame;
float FPSManager::m_previousFrame;
unsigned int FPSManager::m_FPSTime;
float FPSManager::m_whenGameStarted;

void FPSManager::Initialize(unsigned int FPS)
{
    m_FPSTime = 1000.f / FPS;
    m_lastFrame = getNow();
    m_previousFrame = m_lastFrame;
    m_whenGameStarted = m_lastFrame;
}

float FPSManager::getElapsedTime()
{
    return m_lastFrame - m_previousFrame;
}

float FPSManager::getTime()
{
    return m_lastFrame - m_whenGameStarted;
}

float FPSManager::makeCalcWithElapsedTime(float someValue)
{
    return (getElapsedTime() / 1000) * someValue;
}

bool FPSManager::shouldDrawNewFrame()
{
    if(m_FPSTime < timePassedSinceLastFrame()){
        updateLastFrameTime();
        return true;
    }

    return false;
}

void FPSManager::updateLastFrameTime()
{
    m_previousFrame = m_lastFrame;

    m_lastFrame = getNow();
}

float FPSManager::timePassedSinceLastFrame()
{
    return getNow() - m_lastFrame;
}

float FPSManager::getNow()
{
    return std::chrono::duration_cast<std::chrono::duration<
            float, std::milli>>(std::chrono::steady_clock::now().time_since_epoch()).count();
}
