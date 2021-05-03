#include "Star.h"
#include <vector>
#include <unordered_set>
#pragma once

class BFS {
    public:
        std::vector<Star*> StarTraversal(Star* star); // traversal from one start point

        std::vector<Star*> GraphTraversal(const std::vector<Star*> nodeList); // call bfs small on every vertex

        bool canTravel(Star* start, Star* end); //check if there is a path between two stars
};