#include "Visualizer.h"

Visualizer::Visualizer(const std::unordered_map<std::string, Star*> &name_to_star_ptr, const std::vector<Star*> &stars, const std::vector<std::string> &names_in_path) {
    name_to_star_ptr_ = name_to_star_ptr;
    stars_ = stars;
    names_in_path_ = names_in_path;
}

void Visualizer::CreateSnapshot(double multiplier) {
    
}

