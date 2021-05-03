#include "StarInitializer.h"
#include "BFS.h"
#include "AStar.h"
#include "Visualizer.h"
#include <iostream>

int main() {
    StarInitializer star_initializer("data.csv", 50);

    std::vector<Star*> starList = star_initializer.getStarList();
    BFS bfs;
    std::vector<Star> fullTraversal = bfs.GraphTraversal(starList);
    std::cout << fullTraversal.size() << std::endl;

    AStar astar;
    std::vector<std::string> names = astar.findShortestPathAStar(&starList[0], &starList[100]);
    std::cout<<names.size()<<std::endl;

    std::vector<Star*> star_ptr_list;
    for (Star& star: starList) {
        star_ptr_list.push_back(&star);
    }

    Visualizer test_visualizer(star_ptr_list, names);

    cs225::PNG* png_ptr = test_visualizer.GetXYSizeZ(2);
    png_ptr->writeToFile("test.png");

    return 0;
}