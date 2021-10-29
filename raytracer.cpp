#include <iostream>
#include <fstream>
#include <vector>
#include "Vector.h"
#include "Camera.h"
#include "sceneobject.h"
#include "Ray.h"
#include "Trace.h"
#include "Sphere.h"
#include "Plane.h"
#include "ImagePlane.h"

using namespace std;


int main(int argc, const char* argv[]){

  
  int nx = 1024;
  int ny = 768;

  //set up image plane
  ImagePlane image (nx, ny);
  
  
  //container for scene objects
  vector <SceneObject *> content;

  //initialize the plane
  chromeball::Vector point(0,2,0);
  chromeball::Vector normal(0,1,0);
  chromeball::Color pColor;
  pColor.r= 0;
  pColor.g= 0.5;
  pColor.b = 1;

  //initialize the sphere
  chromeball::Vector center(1,2,15);
  int radius = 3;
  chromeball::Color sColor;
  sColor.r = 0.5;
  sColor.g = 1;
  sColor.b = 0;

  //initialize the camera
  chromeball::Vector position(0,0,0);
  chromeball::Vector viewd(0,0,1);
  chromeball::Vector up(0,1,0);
  float hfov = 1.5708;
  float aspect = 1.3333;
  Camera camera(position, viewd, up, hfov, aspect);

  //push back objects
  Plane plane (point, normal, pColor);
  content.push_back(&plane);

  Sphere sphere (center, radius, sColor);
  content.push_back(&sphere);


 
  Tracer trace;
  
  for(int j = 0; j < ny; j++){
    for(int i = 0; i < nx; i++){

      float x = (float) i / (float) nx;
      float y = (float) j / (float) ny;
      
      
      Ray ray(camera.eye(), camera.view(x,y));
      chromeball::Color c = trace.Trace(ray, content);
      image.setcolor(i,j,c);
    }
  }

  //get all pixel data
  chromeball::Color* data = image.returnData();

  //open output stream
  ofstream output;
   output.open(argv[1]);

  

  if(!(output.is_open())){
    cout << "Error, output file is not open";
    return 1;
  }

  //print out output ppm file
  output << "P3\n";
  output << nx << " " << ny << "\n";
  output << 255 << endl;

  
  for(int i = 0; i < nx*ny -1; i++){
    output 
    << (int) (data[i].r * 255) << " " 
    << (int) (data[i].g * 255) << " " 
    << (int) (data[i].b * 255) << " " << endl;  
  }

  delete data;
  image.~ImagePlane();
  output.close();


}

