#pragma once

#include "Star.h"

#include <vector>
#include <string>
#include <fstream>
#include <math.h>

class StarInitializer {
  public:
    StarInitializer(const std::string& data_filename, double fuel_amount);
    const std::vector<Star>& getStarList() const;

  private:
    void LoadStarsFromCSV(const std::string& data_filename);
    double GetDistanceBetweenStars(const Star& star_1, const Star& star_2) const;
    void AddStarNeighborsToStarObjects();

    std::vector<Star> star_list_;
    double fuel_amount_;
};