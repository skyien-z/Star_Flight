#include "Star.h"
#include <vector>
#include <string>
#pragma once

class AStar {
    public:
        std::vector<std::string> findShortestPathAStar(Star* begin, Star* end);
};