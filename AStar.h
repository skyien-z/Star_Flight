#include "Star.h"
#include <vector>
#include <string>
#pragma once

class AStar {
    public:
        /**
         * @brief Executes the A* pathfinding algorithm, generating the shortest path from the begin star to the end star
         * 
         * @param begin the starting destination of the A* algorithm
         * @param end the ending destination of the A* algorithm
         * @return a vector that contains the shortest path of stars from the start to end destination
         */
        std::vector<std::string> findShortestPathAStar(Star* begin, Star* end);
};