/*
 Copyright (C) Johan Ceuppens 2011
*/
#include "RayMantaPolygon.h"
#include "Draw2.h"

namespace ray3d {

int Polygon::draw(SDL_Surface *screen)
{
	#define NIL (0)
	std::vector<Point>::iterator pi = _points.begin();
      
	for (std::vector<Point>::iterator vi = _points.begin(); vi != _points.end(); vi++ ) {//FIXME _points.begin()++
		int x1 = (*vi).get_x();
		int y1 = (*vi).get_y();
		int x2 = (*pi).get_x();
		int y2 = (*pi).get_y();
		drawline(screen, &x1,&y1,&x2,&y2,0xff);
		pi = vi;
	}
	return 0;
}

}
