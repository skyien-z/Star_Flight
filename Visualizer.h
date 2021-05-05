#pragma once

#include "cs225/PNG.h"
#include "AStar.h"
#include <unordered_map>
#include <string>
#include <utility>

using namespace cs225;

class Visualizer {
  public:
        Visualizer(const std::vector<Star*> &stars, 
                   const std::vector<std::string> &names_in_path);

        // allow user to choose how "zoomed-in" they want their perspective of the stars to be
        PNG* GetXYSizeZ(double multiplier);

        PNG* GetXZSizeY(double multiplier);
        
        PNG* GetYZSizeX(double multiplier);

        Visualizer(const Visualizer& other_visualizer);

        const Visualizer & operator=(const Visualizer& other_visualizer);

        ~Visualizer();

  private: 
        std::vector<Star*> stars_;
        std::unordered_map<std::string, bool> name_in_path_map_;

        PNG* XY_size_Z_;
        PNG* XZ_size_Y_;
        PNG* YZ_size_X_;

        static const int EDGE_ = 1000;

        std::pair<int, int> CartesianToPNGCoordinates(int x, int y);
        
        void DrawStar(PNG*& star_ptr, int x_axis_png_val, int y_axis_png_val, int radius, bool is_in_astar_path);

        void ColorPixelWhite(HSLAPixel & pixel);
        void ColorPixelGreen(HSLAPixel & pixel);
        void ColorPixelGold(HSLAPixel & pixel);

        void __copy(const Visualizer& other_visualizer);
};