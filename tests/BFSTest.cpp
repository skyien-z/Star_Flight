#include "../StarInitializer.h"
#include "../Star.h"
#include "../BFS.h"
#include "../cs225/catch/catch.hpp"
#include <iostream>


TEST_CASE("Testing canTravel", "[weight=1]") {

  StarInitializer test_initializer("/Users/keesanpatel/kpate360-kyliez2-shi46-srirams5/test_data/test_data_small.csv", 50);
  std::vector<Star> loaded_stars = test_initializer.getStarList();
  BFS traversal;
  //Star &start = loaded_stars[0];
  //std::vector<Star*> solution ;
  //solution = traversal.StarTraversal(&loaded_stars[0]);
  bool result = traversal.canTravel(&loaded_stars[0], &loaded_stars[2]);
  //std::cout << loaded_stars.front().GetStarName() << std::endl;
 // REQUIRE(1==1);


 
}