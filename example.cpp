#include <iostream>
#include "timecontroller.h"

// Example

int main()
{
    // Created our class TM
    TimeController TM;
    int objectVelocity = 100;

    // Updating time
    TM.updateTime();

    // Output 10000 asterisks
    for(unsigned int i = 0; i < 10000; ++i)
        std::cout << "*" << std::endl;

    // Update time after process
    TM.updateTime();

    // Output the elapsed time as double
    std::cout << "It took " << TM.getElapsedTime() << " milliseconds to output 10000 asterisks" << std::endl;

    // Output object
    std::cout << TM.makeCalcWithElapsedTime(objectVelocity) << std::endl;

    return 0;
}
