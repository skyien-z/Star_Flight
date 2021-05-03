#include "Visualizer.h"

Visualizer::Visualizer(const std::vector<Star*>& stars, 
                       const std::vector<std::string>& names_in_path) :
                       stars_(stars) {
    XY_size_Z_ = new PNG(EDGE_, EDGE_);
    XZ_size_Y_ = new PNG(EDGE_, EDGE_);
    YZ_size_X_ = new PNG(EDGE_, EDGE_);
    
    for (const string & name: names_in_path) {
        name_in_path_map_[name] = true;
    }
}

// (0, 0) in Cartesian is (EDGE_/2, EDGE_/2)
std::pair<int, int> Visualizer::CartesianToPNGCoordinates(int x, int y) {
    int origin = EDGE_/2;

    return std::make_pair(origin + x, origin + y);
}

PNG* Visualizer::GetXYSizeZ(double multiplier) {
    for (unsigned i = 0; i <stars_.size(); i++) {
        int scaled_x = stars_[i]->GetX() * multiplier;
        int scaled_y = stars_[i]->GetY() * multiplier;
        int size = std::log(std::abs(stars_[i]->GetZ())) * multiplier;

        std::pair<int, int> png_axis = CartesianToPNGCoordinates(scaled_x, scaled_y);
        int PNG_X = png_axis.first;
        int PNG_Y = png_axis.second;

        if (PNG_X >= EDGE_ || PNG_X < 0 ||
            PNG_Y >= EDGE_ || PNG_Y < 0) {
            continue;
        }

        bool star_in_path = name_in_path_map_[stars_[i]->GetStarName()];
        DrawStar(XY_size_Z_, PNG_X, PNG_Y, size, star_in_path);
    }
    return XY_size_Z_;
}

PNG* Visualizer::GetXZSizeY(double multiplier) {
    for (unsigned i = 0; i <stars_.size(); i++) {
        int scaled_x = stars_[i]->GetX() * multiplier;
        int size = std::log(std::abs(stars_[i]->GetY())) * multiplier;
        int scaled_z = stars_[i]->GetZ() * multiplier;

        std::pair<int, int> png_axis = CartesianToPNGCoordinates(scaled_x, scaled_z);
        int PNG_X = png_axis.first;
        int PNG_Z = png_axis.second;

        if (PNG_X >= EDGE_ || PNG_X < 0 ||
            PNG_Z >= EDGE_ || PNG_Z < 0) {
            continue;
        }

        bool star_in_path = name_in_path_map_[stars_[i]->GetStarName()];
        DrawStar(XZ_size_Y_, PNG_X, PNG_Z, size, star_in_path);
    }
    return XZ_size_Y_;
}

PNG* Visualizer::GetYZSizeX(double multiplier) {
    for (unsigned i = 0; i <stars_.size(); i++) {
        int size = std::log(std::abs(stars_[i]->GetX())) * multiplier;
        int scaled_y = stars_[i]->GetY() * multiplier;
        int scaled_z = stars_[i]->GetZ() * multiplier;

        std::pair<int, int> png_axis = CartesianToPNGCoordinates(scaled_y, scaled_z);
        int PNG_Y = png_axis.first;
        int PNG_Z = png_axis.second;

        if (PNG_Y >= EDGE_ || PNG_Y < 0 ||
            PNG_Z >= EDGE_ || PNG_Z < 0) {
            continue;
        }  

        bool star_in_path = name_in_path_map_[stars_[i]->GetStarName()];
        DrawStar(YZ_size_X_, PNG_Y, PNG_Z, size, star_in_path);  
    }
    return YZ_size_X_;
}

void Visualizer::DrawStar(PNG*& star_ptr, int x_axis_png_val, int y_axis_png_val,
 int radius, bool is_in_astar_path) {
    for (int x = x_axis_png_val - radius; x < x_axis_png_val + radius; x++) {
        if (is_in_astar_path) {
            ColorPixelGreen(star_ptr->getPixel(x, y_axis_png_val));
        } else {
            ColorPixelWhite(star_ptr->getPixel(x, y_axis_png_val));
        }
    }

    for (int y = y_axis_png_val - radius; y < y_axis_png_val + radius; y++) {
        if (is_in_astar_path) {
            ColorPixelGreen(star_ptr->getPixel(x_axis_png_val, y));
        } else {
            ColorPixelWhite(star_ptr->getPixel(x_axis_png_val, y));
        }
    }
 }

 void Visualizer::ColorPixelWhite(HSLAPixel & pixel) {
    if (pixel.h != 0) {
        return; // Do not override stars in path; the black background has h = 0
    }
    pixel.l = 1;
    pixel.a = 1;
 }

 void Visualizer::ColorPixelGreen(HSLAPixel & pixel) {
    pixel.h = 120;
    pixel.s = 1;
    pixel.l = 0.5;
    pixel.a = 0.9;
 }

 void Visualizer::ColorPixelGold(HSLAPixel & pixel) {
    pixel.h = 60;
    pixel.s = 1;
    pixel.l = 0.5;
    pixel.a = 1;
 }

 Visualizer::~Visualizer() {
    delete XY_size_Z_;
    delete XZ_size_Y_;
    delete YZ_size_X_;
}

Visualizer::Visualizer(const Visualizer& other_visualizer) {
    __copy(other_visualizer);
}

const Visualizer & Visualizer::operator=(const Visualizer& other_visualizer) {
    delete XY_size_Z_;
    delete XZ_size_Y_;
    delete YZ_size_X_;

    __copy(other_visualizer);
    return *this;
}

void Visualizer::__copy(const Visualizer& other_visualizer) {
    stars_ = other_visualizer.stars_;
    name_in_path_map_ = other_visualizer.name_in_path_map_;

    XY_size_Z_ = new PNG(other_visualizer.EDGE_, other_visualizer.EDGE_);
    *XY_size_Z_ = *other_visualizer.XY_size_Z_;

    XZ_size_Y_ = new PNG(other_visualizer.EDGE_, other_visualizer.EDGE_);
    *XZ_size_Y_ = *other_visualizer.XZ_size_Y_;

    YZ_size_X_ = new PNG(other_visualizer.EDGE_, other_visualizer.EDGE_);
    *YZ_size_X_ = *other_visualizer.YZ_size_X_;
}
