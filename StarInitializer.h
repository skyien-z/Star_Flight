#pragma once

#include "Star.h"

#include <vector>
#include <string>
#include <fstream>
#include <math.h>
#include <unordered_map>

class StarInitializer {
  public:
    StarInitializer(const std::string& data_filename, double fuel_amount);
    const std::vector<Star>& getStarList() const;
    const std::unordered_map<std::string, Star*> GetNameToStarPtr();

  private:
    void LoadStarsFromCSV(const std::string& data_filename);
    double GetDistanceBetweenStars(const Star& star_1, const Star& star_2) const;
    void AddStarNeighborsToStarObjects();

    std::vector<Star> star_list_;
    std::unordered_map<std::string, Star*> name_to_star_ptr;
    double fuel_amount_;
};