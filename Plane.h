#include "Vector.h"
#include "sceneobject.h"

#ifndef PLANE_H
#define PLANE_H


using namespace std;

class Plane: public SceneObject{
  public:
      Plane(chromeball::Vector position, chromeball::Vector n_direction, chromeball::Color & c):
      color(c), position(position), n_direction(n_direction){}
      float intersection (const Ray &r) const;
      const chromeball::Color get_color() const;
private:
      chromeball::Color color;
      chromeball::Vector position;
      chromeball::Vector n_direction;

};

#endif