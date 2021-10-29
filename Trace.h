#include "Vector.h"
#include <vector>
#include <iostream>
#include "Ray.h"
#include "ImagePlane.h"
#include "sceneobject.h"
#include <math.h>

#ifndef TRACE_H
#define TRACE_H

using namespace std;

class Tracer {
public:
  chromeball::Color Trace( const Ray&r, const vector <SceneObject *>& content); 
};


#endif