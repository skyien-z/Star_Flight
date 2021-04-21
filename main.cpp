#include "StarInitializer.h"
#include "BFS.h"

#include <iostream>

int main() {
    StarInitializer star_initializer("data.csv", 100000);
    // for (const Star& star : star_initializer.getStarList()) {
    //     std::cout << star.GetStarName() << " (" << star.GetX() 
    //     << "," << star.GetY() << "," << star.GetZ() << ")" << std::endl;
    // }

    const std::vector<Star>& starList = star_initializer.getStarList();
    BFS bfs;
    std::vector<Star*> fullTraversal = bfs.GraphTraversal(starList);
    std::cout << fullTraversal.size() << std::endl;
    return 0;
}