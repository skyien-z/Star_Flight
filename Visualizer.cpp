#include "Visualizer.h"

Visualizer::Visualizer(const std::unordered_map<std::string, Star*> &name_to_star_ptr, 
                       const std::vector<Star*> &stars, 
                       const std::vector<std::string> &names_in_path) {
    name_to_star_ptr_ = name_to_star_ptr;
    stars_ = stars;
    names_in_path_ = names_in_path;

    XY_size_Z_ = new PNG(WIDTH_, LENGTH_);
    XZ_size_Y_ = new PNG(WIDTH_, LENGTH_);
    YZ_size_X_ = new PNG(WIDTH_, LENGTH_);
}

void Visualizer::CreateSnapshot(double multiplier) {
    for (unsigned i = 0; i <stars_.size(); i++) {

    }
}

// (0, 0) in Cartesian is (WIDTH_/2, LENGTH_/2)
std::pair<int, int> Visualizer::CartesianToPNGCoordinates(int x, int y) {
    int origin = (WIDTH_/2, LENGTH_/2);

    return std::make_pair(origin + x, origin + y);
}

PNG* Visualizer::GetXYSizeZ() {
    return XY_size_Z_;
}

PNG* Visualizer::GetXZSizeY() {
    return XZ_size_Y_;
}

PNG* Visualizer::GetYZSizeX() {
    return YZ_size_X_;
}

Visualizer::~Visualizer() {
    delete XY_size_Z_;
    delete XZ_size_Y_;
    delete YZ_size_X_;
}