#include "Trace.h"


chromeball::Color Tracer::Trace(const Ray & r, const vector <SceneObject *>& content){

  //decides which object is closer
  float tmin = 1.0e20;
  chromeball::Color c {0,0,0};

 
  for (int k = 0; k < (int) content.size(); k++){
      float t = (*content[k]).intersection(r);
      if (t > 0 && t < tmin){
        tmin = t;
        c = (*content[k]).get_color();
      }
  }
  

  return c;

}
