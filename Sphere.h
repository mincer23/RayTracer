#include "Vector.h"
#include "sceneobject.h"

#ifndef SPHERE_H
#define SPHERE_H


using namespace std;


class Sphere: public SceneObject{
  public:
    Sphere(chromeball::Vector center, int radius, chromeball::Color & c):
    color(c), position(center), radius(radius) {}
    float intersection (const Ray &r) const;
    const chromeball::Color get_color() const;
    
  private:
    chromeball::Color color;
    chromeball::Vector position;
    int radius;   
};

#endif
