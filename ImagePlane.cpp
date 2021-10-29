#include "ImagePlane.h"

//gets the color of a specific pixel
chromeball::Color ImagePlane::getcolor(int i, int j) const{

  int ip = i + Nx * j;
  return data[ip];

}

//sets the color at a specific pixel
void ImagePlane::setcolor(int i, int j, const chromeball::Color &c){

int ip = i + Nx * j;

data[ip] = c;
  
}

//gets the number of horizontal pixels
const int ImagePlane::getnx() const{
  return Nx;
}

//gets the number of vertical pixels
const int ImagePlane::getny() const{
  return Ny;
}

//returns the pixel data
chromeball::Color* ImagePlane::returnData(){
  return data;
}

//destructor for data
ImagePlane::~ImagePlane(){
  delete data;
}