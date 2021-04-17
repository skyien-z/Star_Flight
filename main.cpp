#include "Graph.h"

#include <iostream>

int main() {
    Graph graph("data.csv");
    for (auto it : graph.getStarList()) {
        std::cout << it.name << " (" << it.x << "," << it.y << "," << it.z << ")" << std::endl;
    }
    return 1;
}