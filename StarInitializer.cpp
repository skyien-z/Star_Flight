#include "StarInitializer.h"

#include <iostream>

StarInitializer::StarInitializer(const std::string& data_file_name, double fuel_amount) {
    fuel_amount_ = fuel_amount;
    LoadStarsFromCSV(data_file_name);
    AddStarNeighborsToStarObjects();
}

void StarInitializer::LoadStarsFromCSV(const std::string& data_file_name) {
    std::ifstream data_stream(data_file_name);
    if (data_stream.fail()) {   
        std::cout << "The file failed to open" << std::endl;
    }
    while (data_stream.good()) {
        int id;      
        data_stream >> id;
        data_stream.get();     // remove unnecessary commas

        std::string proper;
        std::getline(data_stream, proper, ',');
        if (proper.empty()) {
            continue;
        }
        double x; double y; double z;

        data_stream >> x;
        data_stream.get();

        data_stream >> y;
        data_stream.get();

        data_stream >> z;
        data_stream.get();

        star_list_.push_back(new Star(id, proper, x, y, z));
    }
}

void StarInitializer::AddStarNeighborsToStarObjects() {
    for (Star* this_star : star_list_) {
        // maps star name to a pointer to its address in memory
        name_to_star_ptr_map_[this_star->GetStarName()] = this_star;
        for (Star* star_to_compare : star_list_) {
            if (*this_star == *star_to_compare) {   // equality compared by star id
                continue;       // Prevents star from adding itself as a neighbor
            }

            double distance_apart = GetDistanceBetweenStars(this_star, star_to_compare);

            if (distance_apart <= fuel_amount_) {
                this_star->AddNeighboringStar(star_to_compare, distance_apart);
            }
        }
    }
}

double StarInitializer::GetDistanceBetweenStars(Star*& star_1, Star*& star_2) const {
    double delta_x = pow(star_1->GetX() - star_2->GetX(), 2);
    double delta_y = pow(star_1->GetY() - star_2->GetY(), 2);
    double delta_z = pow(star_1->GetZ() - star_2->GetZ(), 2); 

    return sqrt(delta_x + delta_y + delta_z);
}

void StarInitializer::CopyHelper(const StarInitializer& other_star_initializer) {
    fuel_amount_ = other_star_initializer.fuel_amount_;

    // Initializes star_list_ for this star 
    std::vector<Star*> other_stars = other_star_initializer.star_list_;
    for (unsigned i = 0; i < other_stars.size(); i++) {
        // allocate new memory on heap
        Star* new_star_ptr = new Star(other_stars[i]->GetStarId(), other_stars[i]->GetStarName(),
        other_stars[i]->GetX(), other_stars[i]->GetY(), other_stars[i]->GetZ());

        star_list_.push_back(new_star_ptr);
    }

    AddStarNeighborsToStarObjects();    // Initializes name_to_star_ptr_map_ and adds neighboring stars
}

StarInitializer::StarInitializer(const StarInitializer& other_star_initializer) {
    CopyHelper(other_star_initializer);
}

const StarInitializer & StarInitializer::operator=(const StarInitializer& other_star_initializer) {
    for (Star*& star: star_list_) {
        delete star;    // deallocates all previous memory
    }

    star_list_.clear();
    name_to_star_ptr_map_.clear();  // clears class member variables

    CopyHelper(other_star_initializer);     // copies StarInitializer object
    return *this;
}

StarInitializer::~StarInitializer() {
    for (Star*& star: star_list_) {
        delete star;
    }
}

const std::vector<Star*>& StarInitializer::GetStarList() const {
    return star_list_;
}

const std::unordered_map<std::string, Star*> StarInitializer::GetNameToStarPtr() {
    return name_to_star_ptr_map_;
} 