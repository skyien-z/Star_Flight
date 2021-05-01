#pragma once

#include "cs225/PNG.h"
#include "AStar.h"
#include <unordered_map>
#include <string>

using namespace cs225;

class Visualizer {
    public:
        Visualizer(const std::unordered_map<std::string, Star*> &name_to_star_ptr, const std::vector<Star*> &stars, const std::vector<std::string> &names_in_path);
        // allow user to choose how "zoomed-in" they want their perspective of the stars to be
        void CreateSnapshot(double multiplier);

    private: 
        std::unordered_map<std::string, Star*> name_to_star_ptr_;
        std::vector<Star*> stars_;
        std::vector<std::string> names_in_path_;
        PNG* XYZ;
        PNG* XZY;
        PNG* YZX;
};