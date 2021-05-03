#pragma once

#include "Star.h"

#include <vector>
#include <string>
#include <fstream>
#include <math.h>
#include <unordered_map>

class StarInitializer {
  public:
    /**
     * @brief Construct a new Star Initializer object
     * 
     * @param data_filename 
     * @param fuel_amount 
     */
    StarInitializer(const std::string& data_filename, double fuel_amount);

    const std::vector<Star*>& getStarList() const;
    const std::unordered_map<std::string, Star*> GetNameToStarPtr();

  private:
    /**
     * @brief Load stars from the CSV
     * 
     * @param data_filename data file from which to load star
     */
    void LoadStarsFromCSV(const std::string& data_filename);

    /**
     * @brief Get the Distance Between Stars object
     * 
     * @param star_1 first star to compute distance from
     * @param star_2 second star to compute distance from
     * @return double that is the distance between the stars
     */
    double GetDistanceBetweenStars(Star*& star_1, Star*& star_2) const;
    
    /**
     * @brief Adds each star's neighbors to its neighboring stars list
     */
    void AddStarNeighborsToStarObjects();

    std::vector<Star*> star_list_;
    double fuel_amount_;
};