#include "../StarInitializer.h"
#include "../AStar.h"
#include "../cs225/catch/catch.hpp"

TEST_CASE("Testing A* Small", "[weight=1]") {
  StarInitializer test_initializer("test_data/test_data_small.csv", 50);
  std::vector<Star*> loaded_stars = test_initializer.GetStarList();
  AStar aStar;
  std::vector<std::string> shortest_path = aStar.findShortestPathAStar(loaded_stars[0], loaded_stars[2]);
  std::vector<std::string> output = {"Sol", "Caph"};
  REQUIRE(shortest_path == output);
}

TEST_CASE("Testing A* Medium", "[weight=1]") {
  StarInitializer test_initializer("test_data/test_data_med.csv", 40);
  std::vector<Star*> loaded_stars = test_initializer.GetStarList();
  AStar aStar;
  std::vector<std::string> shortest_path = aStar.findShortestPathAStar(loaded_stars[0], loaded_stars[2]);
  std::vector<std::string> output = {"Sol", "A", "B"};
  REQUIRE(shortest_path == output);
}

TEST_CASE("Testing A* Large", "[weight=1]") {
  StarInitializer test_initializer("test_data/test_data_large.csv", 37);
  std::vector<Star*> loaded_stars = test_initializer.GetStarList();
  AStar aStar;
  std::vector<std::string> shortest_path = aStar.findShortestPathAStar(loaded_stars[0], loaded_stars[7]);
  std::vector<std::string> output = {"Sol", "B", "A", "G"};
  REQUIRE(shortest_path == output);
}