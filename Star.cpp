#include "Star.h"

Star::Star(int id, std::string name, double x, double y, double z) 
: id_(id), name_(name), x_(x), y_(y), z_(z), neighboring_stars_() {}

double Star::GetX() const {
    return x_;
}

double Star::GetY() const {
    return y_;
}

double Star::GetZ() const {
    return z_;
}

int Star::GetStarId() const {
    return id_;
}

const std::string& Star::GetStarName() const {
    return name_;
}

bool Star::operator==(const Star& other_star) const {
    return id_ == other_star.GetStarId();
}

const std::vector<Star*>& Star::GetNeighboringStarsList() const {
    return neighboring_stars_;
}

void Star::AddNeighboringStar(Star* neighbor_star) {
    neighboring_stars_.push_back(neighbor_star);
}