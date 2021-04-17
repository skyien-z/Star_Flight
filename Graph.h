#pragma once

#include "Star.h"

#include <vector>
#include <string>

class Graph {
  public:
    Graph(const std::string& data_filename);
    const std::vector<Star>& getStarList() const;

  private:
    void load_stars_from_csv(const std::string& data_filename);
    std::vector<Star> node_list;
};