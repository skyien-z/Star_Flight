#pragma once

#include <string>
#include <vector>

class Star {
  public:
  /**
   * @brief Construct a new Star object
   * 
   * @param id Star ID
   * @param name Name of Star
   * @param x Cartesian x coordinate
   * @param y Cartesian y coordinate
   * @param z Cartesian z coordinate
   */
    Star(int id, std::string name, double x, double y, double z);

    /**
     * @brief Add stars that neighbor this star to this neighboring list.
     * 
     * @param neighbor_star star ptr which to add to the neighbors list
     * @param distance_between_stars 
     */
    void AddNeighboringStar(Star* neighbor_star, double distance_between_stars);

    double GetX() const;
    double GetY() const;
    double GetZ() const;

    int GetStarId() const;
    const std::string& GetStarName() const;
    const std::vector<std::pair<Star*, double> >& GetNeighboringStarsList() const;

    /**
     * @brief Checks if two stars have the same id
     * 
     * @param other_star 
     * @return true if star to compare to has same id as this star
     * @return false 
     */
    bool operator==(const Star& other_star) const;

  private:
    int id_;
    std::string name_;
    double x_;
    double y_;
    double z_;

    // Vector of pairs: each pair has a star pointer and the 
    // distance between the other star and this star
    std::vector<std::pair<Star*, double> > neighboring_stars_;
};