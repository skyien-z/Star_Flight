#pragma once

#include <string>

class Star {
  public:
    Star(int id, std::string name, double x, double y, double z);

    double GetStarX() const;
    double GetStarY() const;
    double GetStarZ() const;

    int GetStarId() const;
    const std::string& GetStarName() const;

  private:
    int id_;
    std::string name_;
    double x_;
    double y_;
    double z_;
};