#include "Vector.h"

#ifndef IMAGEPLANE_H
#define IMAGEPLANE_H

using namespace std;

class ImagePlane {
  public:
      //constructor for image plane
      ImagePlane(int nx, int ny):
         Nx(nx), 
         Ny(ny)
         //initialize the 1D data array
        {data = new chromeball::Color [Nx * Ny];}
        //getters and setter
        const int getnx() const;
        const int getny() const;
      chromeball::Color getcolor(int i,int j) const;
      void setcolor(int i, int j, const chromeball::Color &c);
      //returns the pixel data
      chromeball::Color* returnData();
      ~ImagePlane();

  private:
    int Nx, Ny;
    chromeball::Color* data;
};

#endif