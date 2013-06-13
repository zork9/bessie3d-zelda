/*
	copytright 2011 Johan Ceuppens
*/
#ifndef RAYPIXMAPIMAGE_H
#define RAYPIXMAPIMAGE_H

#include<string>
#include "SDL.h"

#include "RayMantaImageBase.h"

class RayMantaPixmapImage : public RayMantaImageBase 
{
 public:
  //RayMantaPixmapImage();
  RayMantaPixmapImage();//Display **dpy, std::string const& filename);
  int init() { return 0; }//XInitImage(image); return 0;}
  ~RayMantaPixmapImage();

  virtual int draw();//Display **dpy, Window *w, int xx, int yy);
  virtual int putpixel(int x, int y, Uint32 pixel);
  virtual unsigned long getpixel(int xx, int yy);

protected:
  //XImage *shape;
	SDL_Surface *image;

}; //class RayMantaPixmapImage

#endif
