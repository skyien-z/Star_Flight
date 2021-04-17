#include "Graph.h"

#include <iostream>
#include <fstream>

Graph::Graph(const std::string& data_filename) {
    load_stars_from_csv(data_filename);
}

const std::vector<Star>& Graph::getStarList() const {
    return node_list;
}

void Graph::load_stars_from_csv(const std::string& data_filename) {
    std::ifstream data(data_filename);

    while (data.good()) {
        std::string id;
        std::string proper;
        std::string x;
        std::string y;
        std::string z;
        
        std::getline(data, id, ',');
        std::getline(data, proper, ',');
        std::getline(data, x, ',');
        std::getline(data, y, ',');
        std::getline(data, z, ',');

        //std::cout << proper << " (" << x << "," << y << "," << z << ")" << std::endl;

        int id_int = std::stoi(id);
        double x_double = std::stod(x);
        double y_double = std::stod(y);
        double z_double = std::stod(z);

        //std::cout << proper << " (" << x_double << "," << y_double << "," << z_double << ")" << std::endl;

        Star temp(id_int, proper, x_double, y_double, z_double);
        node_list.push_back(temp);        
    }
}