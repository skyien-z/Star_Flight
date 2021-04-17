#include "Star.h"

Star::Star(int id, std::string name, double x, double y, double z) 
: id_(id), name_(name), x_(x), y_(y), z_(z) {}

double Star::GetStarX() const {
    return x_;
}

double Star::GetStarY() const {
    return y_;
}

double Star::GetStarZ() const {
    return z_;
}

int Star::GetStarId() const {
    return id_;
}

const std::string& Star::GetStarName() const {
    return name_;
}