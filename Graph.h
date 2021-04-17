#pragma once

#include "Star.h"

#include <vector>
#include <string>

class Graph {
    public:
        Graph(std::string data_filename);
        std::vector<Star> node_list;
    private:
        void read_csv(std::string data_filename);
};