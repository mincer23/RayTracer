#include "Vector.h"

#ifndef RAY_H
#define RAY_H


using namespace std;


class Ray {
public:
  //constructor for a ray using the camera position and view
  Ray(chromeball::Vector r, chromeball::Vector d):
  position(r), direction(d){};
  //getters
  const chromeball::Vector& get_position() const;
  const chromeball::Vector get_direction() const;

private:
  chromeball::Vector& position;
  chromeball::Vector direction;
};

#endif