#include "../StarInitializer.h"
#include "../cs225/catch/catch.hpp"

TEST_CASE("Test Reading File", "[weight=1]") {
  // Use fully qualified file name to load in data––this file only runs on mine (Kylie's) local machine 
  StarInitializer test_initializer("/Users/user/Documents/SP21/final_project_225/test_data/test_data.csv", 200);

  std::vector<Star> loaded_stars = test_initializer.getStarList();
  REQUIRE(loaded_stars.size() == 5);
}

TEST_CASE("Test Loading in Correct Data", "[weight=1]") {
  StarInitializer test_initializer("/Users/user/Documents/SP21/final_project_225/test_data/test_data.csv", 200);
  std::vector<Star> loaded_stars = test_initializer.getStarList();

  std::vector<int> star_ids{0, 676, 744, 1065, 2076};
  std::vector<std::string> star_names{"Sol", "Alpheratz", "Caph", "Algenib", "Ankaa"};
  std::vector<double> x_coordinates{0, 25.974572, 8.600014, 115.664183, 19.083654};
  std::vector<double> y_coordinates{0, 0.951042, 0.344589, 6.687324, 2.198282};
  std::vector<double> z_coordinates{0, 14.461264, 14.409503, 31.442127, -17.483284};

  for (int i = 0; i < 5; i++) {
      REQUIRE(loaded_stars[i].GetStarName() == star_names[i]);
      REQUIRE(loaded_stars[i].GetStarId() == star_ids[i]);
      REQUIRE(loaded_stars[i].GetX() == x_coordinates[i]);
      REQUIRE(loaded_stars[i].GetY() == y_coordinates[i]);
      REQUIRE(loaded_stars[i].GetZ() == z_coordinates[i]);
  }
}