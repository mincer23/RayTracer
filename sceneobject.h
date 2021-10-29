#include "Vector.h"
#include "ray.h"

#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

using namespace std;


class SceneObject{
public:
  // SceneObject():
  // c{0,0,0} {}
  virtual float intersection (const Ray & r) const = 0;
  virtual const chromeball::Color get_color() const = 0;
// private:
//   chromeball::Color c;
};


#endif