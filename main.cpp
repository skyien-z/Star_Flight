#include "Graph.h"

#include <iostream>

int main() {
    Graph graph("data.csv");
    for (auto it : graph.node_list) {
        std::cout << it.name << " (" << it.x << "," << it.y << "," << it.z << ")" << std::endl;
    }
    return 1;
}