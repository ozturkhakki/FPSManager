#include <iostream>
#include "timecontroller.h"

// Example

int main()
{
    // Created our class TM
    TimeController TM;
    int objectVelocityPerSecond = 100;

    // Updating time
    TM.updateTime();

    // Output 10000 asterisks
    for(unsigned int i = 0; i < 1000000; ++i)
        std::cout << "*";

    std::cout << std::endl;

    // Update time after process
    TM.updateTime();

    // Output the elapsed time as double
    std::cout << "It took " << TM.getElapsedTime() << " milliseconds to output 1000000 asterisks" << std::endl;

    // Output object
    std::cout << TM.makeCalcWithElapsedTime(objectVelocityPerSecond) << std::endl;

    return 0;
}

