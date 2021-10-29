#include "Camera.h"
#include <cstdio>


chromeball::Vector Camera::view(float x, float y) const{
  
  float u = ((2.0*x) - 1.0) * tan(hfov/2.0);
  float v = ((2.0*y) - 1.0) * (tan(hfov/2.0) / aspect);

  chromeball::Vector right = up ^ viewd;

  //calculates 
  chromeball::Vector np = u * right + v * up + viewd;
  np.normalize();

  return np;

}

//camera position
chromeball::Vector Camera::eye() const{
   return position;
}
