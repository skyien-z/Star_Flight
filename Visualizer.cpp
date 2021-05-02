#include "Visualizer.h"

Visualizer::Visualizer(const std::unordered_map<std::string, Star*>& name_to_star_ptr, 
                       const std::vector<Star*>& stars, 
                       const std::vector<std::string>& names_in_path) : name_to_star_ptr_(name_to_star_ptr),
                       stars_(stars), names_in_path_(names_in_path) {
    XY_size_Z_ = new PNG(EDGE_, EDGE_);
    XZ_size_Y_ = new PNG(EDGE_, EDGE_);
    YZ_size_X_ = new PNG(EDGE_, EDGE_);
}

void Visualizer::CreateSnapshot(double multiplier) {

}

// (0, 0) in Cartesian is (EDGE_/2, EDGE_/2)
std::pair<int, int> Visualizer::CartesianToPNGCoordinates(int x, int y) {
    int origin = (EDGE_/2, EDGE_/2);

    return std::make_pair(origin + x, origin + y);
}

PNG* Visualizer::GetXYSizeZ(double multiplier) {
    for (unsigned i = 0; i <stars_.size(); i++) {
        int PNG_X = stars_[i]->GetX() * multiplier;
        int PNG_Y = stars_[i]->GetY() * multiplier;
        int PNG_Z = stars_[i]->GetZ() * multiplier;
        if (PNG_X > EDGE_ || PNG_Y > EDGE_) {
            continue;
        }

        bool star_in_path = isStarInPath(stars_[i]->GetStarName());

        star_in_path ? DrawStar(XY_size_Z_, PNG_X, PNG_Y, PNG_Z, true)
                     : DrawStar(XY_size_Z_, PNG_X, PNG_Y, PNG_Z, false);
    }
    return XY_size_Z_;
}

bool Visualizer::isStarInPath(const string& star_name) {
    // Star* this_star_ptr = name_to_star_ptr_[star_name];
    // if (this_star_ptr == nullptr) {
    //     return false;
    // }

    return (std::find(names_in_path_.begin(), names_in_path_.end(),
     star_name) != names_in_path_.end());
}

PNG* Visualizer::GetXZSizeY(double multiplier) {
    for (unsigned i = 0; i <stars_.size(); i++) {
        if (stars_[i]->GetX() * multiplier > EDGE_ ||
            stars_[i]->GetZ() * multiplier > EDGE_) {
            continue;
        }       
    }
    return XZ_size_Y_;
}

PNG* Visualizer::GetYZSizeX(double multiplier) {
    for (unsigned i = 0; i <stars_.size(); i++) {
        if (stars_[i]->GetY() * multiplier > EDGE_ ||
            stars_[i]->GetZ() * multiplier > EDGE_) {
            continue;
        }       
    }
    return YZ_size_X_;
}

Visualizer::~Visualizer() {
    delete XY_size_Z_;
    delete XZ_size_Y_;
    delete YZ_size_X_;
}
