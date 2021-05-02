#pragma once

#include "cs225/PNG.h"
#include "AStar.h"
#include <unordered_map>
#include <string>
#include <utility>

using namespace cs225;

class Visualizer {
  public:
        Visualizer(const std::unordered_map<std::string, Star*> &name_to_star_ptr, 
                   const std::vector<Star*> &stars, 
                   const std::vector<std::string> &names_in_path);

        // allow user to choose how "zoomed-in" they want their perspective of the stars to be
        void CreateSnapshot(double multiplier);

        PNG* GetXYSizeZ();

        PNG* GetXZSizeY();
        
        PNG* GetYZSizeX();

  private: 
        std::unordered_map<std::string, Star*> name_to_star_ptr_;
        std::vector<Star*> stars_;
        std::vector<std::string> names_in_path_;

        PNG* XY_size_Z_;
        PNG* XZ_size_Y_;
        PNG* YZ_size_X_;

        static const int WIDTH_ = 500;
        static const int  LENGTH_ = 500;

        std::pair<int, int> CartesianToPNGCoordinates(int x, int y);

        ~Visualizer();
};