#include <iostream>
#include "FPSManager/fpsmanager.h"

// This actually ends at 980 miliseconds which is
// a problem
//
// There should be a delay function used from an
// external library. C++ doesnt have one and
// this is for the purpose of showing c++11 features
// so i didnt add any delay function
//
// This probably will run using full processor power
// or one of its cores

int main()
{
    unsigned int fpsCount = 0;
    FPSManager::Initialize(60);

    // Run for 60 fps, which should be 1000 ms
    while(fpsCount <= 60){
        if(FPSManager::shouldDrawNewFrame()){
            std::cout << "Current fps drawn is    : " << fpsCount << std::endl;
            std::cout << "Time elapsed            : " << FPSManager::getElapsedTime() << std::endl;
            std::cout << "Time since game started : " << FPSManager::getTime() << std::endl;
            fpsCount++;
        }
    }

    return 0;
}
