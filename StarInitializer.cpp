#include "StarInitializer.h"

#include <iostream>
#include <fstream>

StarInitializer::StarInitializer(const std::string& data_filename, double fuel_amount) {
    fuel_amount_ = fuel_amount;
    LoadStarsFromCSV(data_filename);
    AddStarNeighborsToStarObjects();
}

void StarInitializer::LoadStarsFromCSV(const std::string& data_filename) {
    std::ifstream data_stream(data_filename);

    while (data_stream.good()) {
        int id;      
        data_stream >> id;
        data_stream.get();     // remove unnecessary commas

        std::string proper;
        std::getline(data_stream, proper, ',');

        double x; double y; double z;

        data_stream >> x;
        data_stream.get();

        data_stream >> y;
        data_stream.get();

        data_stream >> z;
        data_stream.get();

        star_list_.push_back(Star(id, proper, x, y, z));      
    }
}

void StarInitializer::AddStarNeighborsToStarObjects() {
    for (Star& this_star : star_list_) {
        for (Star& star_to_compare : star_list_) {

            if (this_star == star_to_compare) {
                continue;       // Prevents star from adding itself as a neighbor
            }

            double distance_apart = GetDistanceBetweenStars(this_star, star_to_compare);

            if (distance_apart <= fuel_amount_) {
                this_star.AddNeighboringStar(&star_to_compare);
            }
        }
    }
}

double StarInitializer::GetDistanceBetweenStars(
    const Star& star_1, const Star& star_2) const {
    double delta_x = pow(star_1.GetX() - star_2.GetX(), 2);
    double delta_y = pow(star_1.GetY() - star_2.GetY(), 2);
    double delta_z = pow(star_1.GetZ() - star_2.GetZ(), 2); 

    return sqrt(delta_x + delta_y + delta_z);
}


const std::vector<Star>& StarInitializer::getStarList() const {
    return star_list_;
}