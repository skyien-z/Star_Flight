#include "StarInitializer.h"
#include "BFS.h"
#include "AStar.h"
#include "Visualizer.h"
#include <iostream>

int main() {
    std::string start_star_name;
    std::string end_star_name;
    double fuel;
    double multiplier;

    std::cout << "Hello! You are a traveler with a high-tech fuel spaceship. From which star do you hail?" << std::endl;
    std::cin >> start_star_name;

    std::cout << "To which star do you wish to go?" << std::endl;
    std::cin >> end_star_name;

    std::cout << "How much fuel can your spaceship hold? Each unit of fuel will allow you to travel one cartesian unit. You can refuel to max capacity at every star you reach." << std::endl;
    std::cin >> fuel;

    std::cout << "We can give you a colored map of your path, how zoomed in would you like it to be?" << std::endl;
    std::cin >> multiplier;

    StarInitializer star_initializer("data.csv", fuel);
    std::unordered_map<std::string, Star*> name_to_star_ptr_map = star_initializer.GetNameToStarPtr();
    
    if (!name_to_star_ptr_map.count(start_star_name) && !name_to_star_ptr_map.count(end_star_name)) {
        std::cout << "One or both of your star names is invalid. Please rerun the program and try again." << std::endl;
        return 1;
    }

    Star* star_star_ptr = name_to_star_ptr_map[start_star_name];
    Star* star_end_ptr = name_to_star_ptr_map[end_star_name];

    BFS bfs;
    if (!bfs.canTravel(star_star_ptr, star_end_ptr)) {
        std::cout << "You do not have enough fuel to travel to the given star. Please rerun the program and try again." << std::endl;
        return 1;
    }

    AStar a_star;
    std::vector<std::string> names_in_path = a_star.findShortestPathAStar(star_star_ptr, star_end_ptr);

    Visualizer path_visualizer(star_initializer.GetStarList(), names_in_path);

    cs225::PNG* png_ptr_1 = path_visualizer.GetXYSizeZ(multiplier);
    cs225::PNG* png_ptr_2 = path_visualizer.GetXZSizeY(multiplier);
    cs225::PNG* png_ptr_3 = path_visualizer.GetYZSizeX(multiplier);

    png_ptr_1->writeToFile("png_files/XY_SizeZ.png");
    png_ptr_2->writeToFile("png_files/XZ_SizeY.png");
    png_ptr_3->writeToFile("png_files/YZ_SizeX.png");

    std::cout << "Your journey will take you along the following stars:" << std::endl;
    for (unsigned i = 0; i < names_in_path.size(); i++) {
        if (i == 0) {
            std::cout << names_in_path[i];
        } else {
            std::cout << ", " << names_in_path[i];
        }
    }
    std::cout << std::endl;

    std::cout << "Your maps are prepared! Happy travels." << std::endl;
    return 0;
}