#include "Star.h"
#include <vector>
#include <unordered_set>
#pragma once

class BFS {
    public:
        /**
        * @brief Performs a BFS traversal starting from one star over all the stars it is connected to.
        *
        * @param star Pointer to the star that will be the start of the traversal
        * @return Vector of star pointers in the traversal.
        */
        std::vector<Star*> StarTraversal(Star* star);

        /**
        * @brief Performs a BFS traversal over the whole graph by calling StarTraversal on every star that has not been visited.
        *
        * @param nodeList Vector of star pointers that will be travered via BFS (starting from the first star in the vector).
        * @return Vector of star pointers in the full traversal.
        */
        std::vector<Star*> GraphTraversal(const std::vector<Star*> nodeList);

        /**
        * @brief Checks if a star has a path to another star.
        *
        * @param start Pointer to the first star.
        * @param end Pointer to the destination star.
        * @return Whether or not a path from the first star to the destination star exists.
        */
        bool canTravel(Star* start, Star* end); //check if there is a path between two stars
};