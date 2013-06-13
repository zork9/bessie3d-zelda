/*
 Copyright (C) Johan Ceuppens 2011
*/

#include<fstream>
#include "RayMantaPixmapTextureModel.h"
#include<cstdlib>
#include<iostream>
#include "Draw.h"

namespace ray3d {	
int PixmapTextureModel::draw(SDL_Surface *screen, int offsetx, int offsety)
{
	//if (_points.empty())
	//NOTE init points
	//FIXME _pixmaptexture.rotatemodel(*this);

	for (std::vector<Point>::iterator vi = _points.begin(); vi != _points.end(); vi++) {
		
		putpixel(screen,(*vi).get_x()+offsetx,(*vi).get_y(),0xff);
	}
	return 0;
}
/*
int PixmapTextureModel::draw2(SDL_Surface *screen)
{

	const std::string filename("./post.xpm");
	//NOTE: do not draw polygon lines, rather texture in between 
	//NOTE: polygons are fixed at 4 points
	ray3d::Polygon poly;
	poly += ray3d::Point(20,20,20);
	poly += ray3d::Point(102,102,102);
	poly += ray3d::Point(120,120,120);
	poly += ray3d::Point(20,20,20);
	_polygons.push_back(poly);
	//for (PolygonVector::iterator vi = _polygons.begin(); vi != _polygons.end(); vi++ ) {
			//for (int i = 0; i < 4; i++) {
			for (int xx = 0; xx < _pixmaptexture.get_w(); xx++) { 
			for (int yy = 0; yy < _pixmaptexture.get_h(); yy++) {
				//Point p1((*vi)[i-1]);
				//Point p2((*vi)[i]);
				Point p1(_polygons[0][0].get_x(),_polygons[0][0].get_y(),1);
				Point p2(xx,yy,1);
				//Point pt = p2.scalex(angle);//_pixmaptexture.get_alpha());
				//pt = pt.scaley(angle);//_pixmaptexture.get_alpha());
				_alpha -= 0.001;
				Point pt(xx*(angle),yy*(angle),1);
				//unsigned long color = 65000;//_pixmaptexture.get_xpmimage().getpixel((int)pt.get_x(), (int)pt.get_y());
				unsigned long color = _pixmaptexture.get_xpmimage().getpixel((int)pt.get_x()%24, (int)pt.get_y()%24);
				values.foreground = color;//RedPixel(*dpy, DefaultScreen(*dpy));//2048;
        			gc = XCreateGC(*dpy, *w, valuemask, &values);
				/////XDrawLine(*dpy, *w, gc, p1.get_x()+(int)pt.get_x(),p1.get_y()+(int)pt.get_y(),p1.get_x()+(int)pt.get_x(),p1.get_y()+(int)pt.get_y());
				XDrawLine(*dpy, *w, gc,20+(int)pt.get_x(),20+(int)pt.get_y(),20+(int)pt.get_x(),20+(int)pt.get_y());
			}
			}
			//}
//		}
		
	return 0;
}
*/


} // namespace ray3d

