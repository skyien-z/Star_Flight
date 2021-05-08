#include "../Visualizer.h"
#include "../StarInitializer.h"

#include "../cs225/catch/catch.hpp"

TEST_CASE("Test Visualizer Copy Constructor", "[weight=1]") {
    StarInitializer star_initializer("test_data/test_data_small.csv", 50);

    std::vector<Star*> starList = star_initializer.GetStarList();

    AStar a_star;
    std::vector<std::string> names = a_star.findShortestPathAStar(starList[0], starList[2]);
    // names = {"Sol", "Caph"} from AStarTest.cpp

    Visualizer test_visualizer(starList, names);

    cs225::PNG* test_png_ptr = test_visualizer.GetXYSizeZ(1);

    Visualizer new_visualizer(test_visualizer);

    cs225::PNG* new_png_ptr = new_visualizer.GetXYSizeZ(1);

    REQUIRE(*test_png_ptr == *new_png_ptr);

}

TEST_CASE("Test Visualizer Copy Assignment Operator", "[weight=1]") {
    StarInitializer star_initializer("test_data/test_data_small.csv", 50);

    std::vector<Star*> starList = star_initializer.GetStarList();

    AStar a_star;
    std::vector<std::string> names = a_star.findShortestPathAStar(starList[0], starList[2]);
    // names = {"Sol", "Caph"} from AStarTest.cpp

    Visualizer test_visualizer(starList, names);

    cs225::PNG* test_png_ptr = test_visualizer.GetXYSizeZ(1);

    Visualizer new_visualizer = test_visualizer;

    cs225::PNG* new_png_ptr = new_visualizer.GetXYSizeZ(1);

    REQUIRE(*test_png_ptr == *new_png_ptr);
}

TEST_CASE("Test Visualizer Creates Correct Pixels in Right Places", "[weight=1]") {
    StarInitializer star_initializer("test_data/test_data_small.csv", 50);

    std::vector<Star*> starList = star_initializer.GetStarList();

    AStar a_star;
    std::vector<std::string> names = a_star.findShortestPathAStar(starList[0], starList[2]);
    // names = {"Sol", "Caph"} from AStarTest.cpp

    Visualizer test_visualizer(starList, names);

    cs225::PNG* test_png_ptr = test_visualizer.GetXYSizeZ(1);

    HSLAPixel green_pixel(120, 1, 0.5, 0.9);

    // Tests that the center of Sol and Caph are colored green
    REQUIRE(test_png_ptr->getPixel(500, 500) == green_pixel);

    REQUIRE(test_png_ptr->getPixel(508, 500) == green_pixel);

    // Tests that the center of Alpheratz is rendered white
    HSLAPixel white_pixel(0, 0, 1);

    REQUIRE(test_png_ptr->getPixel(525, 500) == white_pixel);

}