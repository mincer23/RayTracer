#include "Ray.h"

const chromeball::Vector& Ray::get_position() const{
  return position;
}
const chromeball::Vector Ray::get_direction() const{
  return direction;
}
