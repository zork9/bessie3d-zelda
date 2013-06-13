/*
 Copyright (C) Johan Ceuppens 2011-2012
*/

#include<fstream>
#include "RayMantaTextureModel.h"
#include<cstdlib>
#include "Draw.h"

namespace ray3d {	

int TextureModel::draw(SDL_Surface *screen)
{
	//NOTE: do not draw polygon lines, rather texture in between 
	for (std::vector<Point>::iterator vi = _points.begin(); vi != _points.end(); vi++ ) {
		int x1 = (*vi).get_x();
		int y1 = (*vi).get_y();
		putpixel(screen, x1,y1,0xff);

	}
	return 0;
}



} // namespace ray3d

