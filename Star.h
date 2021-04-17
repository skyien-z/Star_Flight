#pragma once

#include <string>

class Star {
    public:
        Star(int id, std::string name, double x, double y, double z);
        int id;
        std::string name;
        double x;
        double y;
        double z;
};