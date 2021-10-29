#include "Sphere.h"
#include <cstdio>
#include <cmath>

float Sphere::intersection (const Ray &r) const{


//printf("sphere");


  chromeball::Vector rayD = r.get_direction();
  chromeball::Vector rayP = r.get_position();


  chromeball::Vector pos = rayP - position;
  float val = rayD * pos;
  float posmag = pos.magnitude();



  float f = (pow(val, 2) + pow(radius, 2) - pow(posmag, 2));
  float t = -1.0;


  //printf("%f %d %f %f", val, radius, posmag, f);
  

  if ( f < 0){
      t = -1;
  } else if (f == 0){
      t = -rayD * (rayP - position);
  } else if (f > 0){
      float tplus = (-rayD * (rayP - position)) + sqrt(f);
      float tminus = (-rayD * (rayP - position)) - sqrt(f);
      if (tminus < 0 && tplus > 0){
        t = tplus;
      } else if (tminus > 0 && tplus < 0){
        t = tminus;
      } else {
        if(tminus > 0 && tplus > 0 && tplus > tminus){
          t = tminus;
        } else if (tminus > 0 && tplus > 0 && tplus < tminus){
          t = tplus;
        }
      }
  }


//printf("%f", t);

  return t;



}



const chromeball::Color Sphere::get_color() const{
  return color;
}

