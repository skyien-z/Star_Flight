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
     * @param data_filename file from which to contruct stars
     * @param fuel_amount fuel amount decides how many neighboring stars can be
     * reached from a given star
     */
    StarInitializer(const std::string& data_file_name, double fuel_amount);

    /**
     * @brief returns list of star pointers representing all stars in the dataset
     * 
     * @return const reference to list of star pointers of all stars
     * in the dataset
     */
    const std::vector<Star*>& GetStarList() const;

    const std::unordered_map<std::string, Star*> GetNameToStarPtr();

    /**
     * @brief Destroy the Star Initializer object
     */
    ~StarInitializer();

    /**
     * @brief Construct a new Star Initializer object by creating
     * a deep copy of another star initializer object
     * 
     * @param other_star_initializer StarInitializer object to copy
     */
    StarInitializer(const StarInitializer& other_star_initializer);

    /**
     * @brief Creates and returns a deep copy of another star initializer object
     * 
     * @param other_star_initializer StarInitializer object to copy
     * @return const StarInitializer& 
     */
    const StarInitializer& operator=(const StarInitializer& other_star_initializer);

  private:
    /**
     * @brief Load stars from the CSV onto the heap and stores
     * their memory locations into a list of star pointers
     * 
     * @param data_filename csv data file from which to load stars
     */
    void LoadStarsFromCSV(const std::string& data_file_name);

    /**
     * @brief Get the Distance Between Stars objects
     * 
     * @param star_1 first star to compute distance from
     * @param star_2 second star to compute distance from
     * @return double that is the distance between the stars
     */
    double GetDistanceBetweenStars(Star*& star_1, Star*& star_2) const;
    
    /**
     * @brief Adds each star's neighbors to its neighboring stars list (as star pointers)
     */
    void AddStarNeighborsToStarObjects();

    std::vector<Star*> star_list_;
    double fuel_amount_;
    std::unordered_map<std::string, Star*> name_to_star_ptr_map_;

    /**
     * @brief A helper function for the copy constructor and copy assignment operation
     * 
     * @param other_star_initializer StarInitializer object which to copy
     */
    void CopyHelper(const StarInitializer& other_star_initializer);
};