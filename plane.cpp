#include "Plane.h"
#include <cstdio>
#include <cmath>


float Plane::intersection (const Ray &r) const{

  chromeball::Vector rayD = r.get_direction();
  chromeball::Vector rayP = r.get_position();

  float t = -((rayP - position) * n_direction) / (rayD * n_direction);

  float denom = rayD * n_direction;

  if(denom != 0 && t >= 0){
    return t;
  } else {
    return -1;
  }
}

const chromeball::Color Plane::get_color() const{

  return color;

}
