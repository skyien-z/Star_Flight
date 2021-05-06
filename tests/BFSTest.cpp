#include "../StarInitializer.h"
#include "../Star.h"
#include "../BFS.h"
#include "../cs225/catch/catch.hpp"

#include <iostream>
#include <vector>


TEST_CASE("StarTraversal Test", "[weight=1]") {
  StarInitializer test_initializer("test_data/test_data_med.csv", 35);
  std::vector<Star*> loaded_stars = test_initializer.GetStarList();
  BFS traversal;
  std::vector<Star*> starTraversal = traversal.StarTraversal(loaded_stars[0]);
  std::vector<std::string> actual;
  for (auto star : starTraversal) {
    //std::cout << star->GetStarName() << std::endl;
    actual.push_back(star->GetStarName());
  }
  std::vector<std::string> correct{"Sol","A","B","C"};
  REQUIRE(actual == correct);
}

TEST_CASE("GraphTraversal Test", "[weight=1]") {
  StarInitializer test_initializer("data.csv", 35);
  std::vector<Star*> loaded_stars = test_initializer.GetStarList();
  BFS traversal;
  std::vector<Star*> graphTraversal = traversal.GraphTraversal(loaded_stars);
  // for (auto star : graphTraversal) {
  //   std::cout << star->GetStarName() << std::endl;
  // }
  REQUIRE(graphTraversal.size() == 146);
}

TEST_CASE("canTravel Test", "[weight=1]") {
  StarInitializer test_initializer("test_data/test_data_med.csv", 35);
  std::vector<Star*> loaded_stars = test_initializer.GetStarList();
  BFS traversal;
  bool test1 = traversal.canTravel(loaded_stars[0],loaded_stars[1]);
  REQUIRE(test1);
  bool test2 = traversal.canTravel(loaded_stars[0],loaded_stars[4]);
  REQUIRE(!test2);
  bool test3 = traversal.canTravel(loaded_stars[3],loaded_stars[4]);
  REQUIRE(!test3);
}