#include "../StarInitializer.h"
#include "../cs225/catch/catch.hpp"

/**
 * @brief Use fully qualified file name to load in data––this test data file
 * path only works on mine (Kylie's) local machine
 * 
 */

TEST_CASE("Test Reading File", "[weight=1]") {
  StarInitializer test_initializer("test_data/test_data.csv", 200);

  std::vector<Star*> loaded_stars = test_initializer.getStarList();
  REQUIRE(loaded_stars.size() == 5);
}

TEST_CASE("Test Loading in Correct Data", "[weight=1]") {
  StarInitializer test_initializer("test_data/test_data.csv", 200);
  std::vector<Star*> loaded_stars = test_initializer.getStarList();

  std::vector<int> star_ids{0, 676, 744, 1065, 2076};
  std::vector<std::string> star_names{"Sol", "Alpheratz", "Caph", "Algenib", "Ankaa"};
  std::vector<double> x_coordinates{0, 25.974572, 8.600014, 115.664183, 19.083654};
  std::vector<double> y_coordinates{0, 0.951042, 0.344589, 6.687324, 2.198282};
  std::vector<double> z_coordinates{0, 14.461264, 14.409503, 31.442127, -17.483284};

  for (int i = 0; i < 5; i++) {
      REQUIRE(loaded_stars[i] -> GetStarName() == star_names[i]);
      REQUIRE(loaded_stars[i] -> GetStarId() == star_ids[i]);
      REQUIRE(loaded_stars[i] -> GetX() == x_coordinates[i]);
      REQUIRE(loaded_stars[i] -> GetY() == y_coordinates[i]);
      REQUIRE(loaded_stars[i] -> GetZ() == z_coordinates[i]);
  }
}

TEST_CASE("Test Computing Distance Between Stars", "[weight=1]") {
  StarInitializer test_initializer("test_data/test_data.csv", 200);
  std::vector<Star*> loaded_stars = test_initializer.getStarList();

  std::vector<std::pair<Star*, double> > neighbors_of_sol = loaded_stars[0] -> GetNeighboringStarsList();

  std::vector<double> neighboring_distances{29.74409232, 16.82875946, 120.0480357, 25.97467061};

  for (int i = 0; i < 4; i++) {
    REQUIRE(neighbors_of_sol[i].second - neighboring_distances[i] < 0.001);
  }
}

TEST_CASE("Test that Fuel Limits Stars Found", "[weight=1]") {
  // Change fuel here
  StarInitializer test_initializer("test_data/test_data.csv", 30);
  std::vector<Star*> loaded_stars = test_initializer.getStarList();

  std::vector<std::pair<Star*, double> > neighbors_of_sol = loaded_stars[0] -> GetNeighboringStarsList();

  REQUIRE(neighbors_of_sol.size() == 3);  // Star can't be neighbor of itself
  
  std::vector<double> neighboring_distances{29.74409232, 16.82875946, 25.97467061};

  for (int i = 0; i < 3; i++) {
    REQUIRE(neighbors_of_sol[i].second - neighboring_distances[i] < 0.001);
  }
}