#include "StarInitializer.h"

#include <iostream>

int main() {
    StarInitializer star_initializer("data.csv", 100000);
    for (const Star& star : star_initializer.getStarList()) {
        std::cout << star.GetStarName() << " (" << star.GetX() 
        << "," << star.GetY() << "," << star.GetZ() << ")" << std::endl;
    }

    return 0;
}