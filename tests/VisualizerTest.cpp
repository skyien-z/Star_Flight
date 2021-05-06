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