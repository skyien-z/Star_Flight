#pragma once

#include "cs225/PNG.h"
#include "AStar.h"
#include <unordered_map>
#include <string>
#include <utility>

using namespace cs225;

class Visualizer {
  public:
        /**
         * @brief Construct a new Visualizer object with a list of all stars
         * given by a vector of star pointers and a vector of strings of star names
         * in a given path found by the A* algorithm.
         * 
         * @param stars list of star pointers of all stars
         * @param names_in_path names of stars in path from one star to another given by A*
         */
        Visualizer(const std::vector<Star*> &stars, 
                   const std::vector<std::string> &names_in_path);

        // The next three functions behave similarly, so the bulk of the explanation for each
        // can be found in the @brief of GetXYSizeZ––some information in the other two functions
        // is omitted for concision.

        /**
         * @brief Creates and returns a PNG pointer that holds the address of a PNG
         * that renders an image of all stars that fit within the PNG bounds. Stars
         * in the path found by A* will be rendered green while all other stars are 
         * rendered in white. The star Sol, or the sun, is always rendered at the center
         * of the PNG. A multiplier passed in determines the "zoom" level of the images.
         * A larger multiplier value will return a much more zoomed in image around the
         * sun while a smaller value will return a much more faraway shot. The image
         * is plotted with X on the x-axis and Y on the y-axis (X and Y come from the 
         * cartesian coordinates of the stars' dataset; Sol's positioned at (0, 0)) 
         * and Z determines the size of the star––the log of the absolute value of Z 
         * is taken to ensure that the PNG can render all stars that it's asked to render appropriately.
         * 
         * @param multiplier zoom level of image that determines how X and Y are scaled
         * @return PNG* described in @brief above
         */
        PNG* GetXYSizeZ(double multiplier);

        /**
         * @brief Creates and returns a PNG pointer that holds the address of a PNG
         * that renders an image of all stars that fit within the PNG bounds. Stars
         * in the path found by A* will be rendered green while all other stars are 
         * rendered in white. The star Sol, or the sun, is always rendered at the center
         * of the PNG. A multiplier passed in determines the "zoom" level of the images.
         * The image is plotted with X on the x-axis and Z on the y-axis (Sol's positioned
         * at (0, 0)) and Y determines the size of the star.
         * 
         * @param multiplier zoom level of image that determines how X and Z are scaled
         * @return PNG* described in @brief above
         */
        PNG* GetXZSizeY(double multiplier);
        
      /**
         * @brief Creates and returns a PNG pointer that holds the address of a PNG
         * that renders an image of all stars that fit within the PNG bounds. Stars
         * in the path found by A* will be rendered green while all other stars are 
         * rendered in white. The star Sol, or the sun, is always rendered at the center
         * of the PNG. A multiplier passed in determines the "zoom" level of the images.
         * The image is plotted with Y on the x-axis and Z on the y-axis (Sol's positioned at (0, 0)) 
         * and X determines the size of the star.
         * 
         * @param multiplier zoom level of image that determines how Y and Z are scaled
         * @return PNG* described in @brief above
         */
        PNG* GetYZSizeX(double multiplier);
      
       /**
        * @brief Construct a new Visualizer object from an existing Visualizer Object.
        * 
        * @param other_visualizer Visualizer object to copy
        */
        Visualizer(const Visualizer& other_visualizer);

       /**
        * @brief Copy Assignment Operator for the Visualizer object.
        * 
        * @param other_visualizer Visualizer object to copy
        * @return const Visualizer& copy of newly copied visualizer
        */
        const Visualizer & operator=(const Visualizer& other_visualizer);

        /**
         * @brief Destroy the Visualizer object
         */
        ~Visualizer();

  private: 
        std::vector<Star*> stars_;
        // maps name of star to whether or not it is in the given A* path
        std::unordered_map<std::string, bool> name_in_path_map_;
      
       // PNG pointers describe by their respective "Get" functions above
        PNG* XY_size_Z_;
        PNG* XZ_size_Y_;
        PNG* YZ_size_X_;

        const int kEdge = 1000;     // constant pixel size of each PNG edge

        /**
         * @brief Converts cartesian coordinates contained by the star into
         * PNG pixel coordinates (that are always positive) and returns PNG coordinates
         * as a pair.
         * 
         * @param x Cartesian coordinate of the value on the x-axis
         * @param y Cartesian coordinate of the value on the y-axis
         * @return std::pair<int, int> the first value held by the pair is the PNG
         * pixel coordinate of of the value on the x-axis, the second value is the 
         * PNG pixel coordinate of of the value on the y-axis
         */
        std::pair<int, int> CartesianToPNGCoordinates(int x, int y);
        
        /**
         * @brief Draws a star on a given PNG given a PNG*, star location (with x-axis coordinate
         * and y-axis coordinate), a radius, and a boolean decribing whether or not the given
         * star in the A* path. If the star is in the path, render it green, else render it white.
         * 
         * @param star_ptr PNG* which to access PNG on which to draw star
         * @param x_axis_png_val x PNG coordinate value of star center
         * @param y_axis_png_val y PNG coordinate value of star center
         * @param radius number of pixels from the center that the star draws (up, down, left, right)
         * @param is_in_a_star_path true if the star is in the path, false otherwise
         */
        void DrawStar(PNG*& star_ptr, int x_axis_png_val, int y_axis_png_val, int radius, bool is_in_a_star_path);
       
       /**
        * @brief Renders a given pixel white if the pixel is black. Does
        * nothing if the pixel is already a different color.
        * 
        * @param pixel pixel passed by reference to turn white
        */
        void ColorPixelWhite(HSLAPixel & pixel);

      /**
        * @brief Renders a given pixel green.
        * 
        * @param pixel pixel passed by reference to turn green
        */
        void ColorPixelGreen(HSLAPixel & pixel);

      /**
        * @brief Renders a given pixel gold.
        * 
        * @param pixel pixel passed by reference to turn gold
        */
        void ColorPixelGold(HSLAPixel & pixel);

       /**
        * @brief Helper function for copying another visualizer
        * object to this one.
        * 
        * @param other_visualizer Visualizer object to copy
        */
        void CopyHelper(const Visualizer& other_visualizer);
};