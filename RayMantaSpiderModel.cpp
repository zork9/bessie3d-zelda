/*
 Copyright (C) Johan Ceuppens 2011
*/

#include<fstream>
#include "RayMantaSpiderModel.h"
#include<cstdlib>
#include<iostream>
#include "SDL.h"
#include "Draw.h"


namespace ray3d {

int SpiderModel::rotateandsetpoints(SDL_Surface *screen, double thetax, double thetay, double thetaz)
{
	SpiderModel retmodel;//FIXME 
	retmodel.empty_points();//FIXME loads initdraw again
	
	for (std::vector<Point>::iterator vi = get_points().begin(); vi != get_points().end(); vi++) {
			
			Uint32 color = 0xff;//FIXME1get_xpmimage().getpixel((int)pt.get_x(), (int)pt.get_y());
        	Matrix3 rotmx = ray3d::rotatex(_thetax);
        	Matrix3 rotmy = ray3d::rotatey(3.14);
        	Matrix3 rotmz = ray3d::rotatez(_thetaz);
			thetax += 0.1;
			thetay += 0.1;
			thetaz += 0.1;
			Vector3 prot((*vi).get_x(),(*vi).get_y(),(*vi).get_z());
			prot = rotmz*prot;
			prot = rotmy*prot;
			prot = rotmx*prot;
			Point p(prot.get_x(),prot.get_y(),prot.get_z(),color);//FIXME1 color
			//if (color != 0)//alpha channel black
			retmodel.addpoint(p);
			//putpixel(screen,p.get_x()+100,p.get_y()+100,p.get_color());
		
	}
	empty_points();
	set_points(retmodel.get_points());
	return 0;
}


	
int SpiderModel::drawpoints(SDL_Surface *screen, int offsetx, int offsety)
{
	
	for (std::vector<Point>::iterator vi = _points.begin(); vi != _points.end(); vi++) {
		
		//(*vi) += Point(150,0,0);
		putpixel(screen,(*vi).get_x()+offsetx,(*vi).get_y()+offsety,(*vi).get_color());
	}
	return 0;
}

int SpiderModel::drawspider(SDL_Surface *screen, int offsetx, int offsety)
{
	drawpoints(screen,offsetx,offsety);//right leg
	drawpoints(screen,offsetx+10,offsety+10);//right leg
	drawpoints(screen,offsetx+5,offsety+10);//right leg
	drawpoints(screen,offsetx+15,offsety+10);//right leg
	rotateandsetpoints(screen,0,3.14,0);
	drawpoints(screen,offsetx,offsety);//left leg
	drawpoints(screen,offsetx+10,offsety+10);//left leg
	drawpoints(screen,offsetx+5,offsety+10);//left leg
	drawpoints(screen,offsetx+15,offsety+10);//left leg
	return 0;
}

}//namespace ray3d
