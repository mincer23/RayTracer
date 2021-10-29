#include "vector.h"
#include "ImagePlane.h"
#include <math.h>


#ifndef CAMERA_H
#define CAMERA_H
using namespace std;

class Camera{
public:
  Camera(chromeball::Vector position, chromeball::Vector viewd, chromeball::Vector up, float hfov, float aspect):
    position(position),
    viewd(viewd),
    up(up),
    hfov(hfov),
    aspect(aspect)
    {}
  chromeball::Vector view(float x, float y) const;
  chromeball::Vector eye() const;
private:
  chromeball::Vector position;
  chromeball::Vector viewd;
  chromeball::Vector up;
  float hfov;
  float aspect;
};

#endif