/*
 Copyright (C) Johan Ceuppens 2011
*/

#include<fstream>
#include "RayMantaSpiderTexture.h"
#include "RayMantaSpiderModel.h"
#include "RayMantaMatrix3.h"
#include<cstdlib>

namespace ray3d {

/*
* NOTE : You map the _xpmimage 
* (xpm XImage, see file RayMantaPixmapImage.h/.cc)
* onto the walls, curved,dungeon tower and straight walls.
*/	
//main draw method

int SpiderTexture::initdraw(SpiderModel& model)
{
	//_thetax = 1.5;
	//_thetay = 1.5;
	//_thetaz = 1.5;

	initdraw1(model);//,/*offsetx+*/100,/*offsety+*/100);
	return 0;
}

int SpiderTexture::initdraw1(SpiderModel& model)
{

	model.empty_points();
	initspiderleg(model);
	initclover(model);//FIXME1
	return 0;
}

int SpiderTexture::initconeorcylindercurvedY(SpiderModel& model)
{	double prevx=0,prevy=0;
	_alpha = 4;
	_beta = 10;
	_gamma = 10;
	double Y = 4;
for (int zz = 0; zz < _legz; zz ++) {
	for (int yy = 0; yy < _legh; yy ++) {
			//_beta *= 0.9;
			Y *= 0.75;
		for (int xx = 0; xx < _legw*Y; xx ++) { 
			Point pt(xx*_alpha,yy*_beta,zz*_gamma);
			double ptx = pt.get_x()*_alpha,
				pty = pt.get_y()*_beta,
				ptz = pt.get_z()*_gamma;
			//unsigned long color = 65000;
			unsigned long color = 0xff;//FIXME1 get_xpmimage().getpixel((int)(ptx*_alpha)%_w, (int)(pty*_beta)%_h);
        		Matrix3 rotmx = ray3d::rotatex(_thetax);
        		Matrix3 rotmy = ray3d::rotatey(_thetay);
        		Matrix3 rotmz = ray3d::rotatez(_thetaz);
			_thetax += 0.001;
			_thetay += 0.001;
			_thetaz += 0.001;
			Vector3 prot(ptx,pty,zz*_gamma);
			//prot = rotmz*prot;
			//prot = rotmy*prot;
			prot = rotmx*prot;
		
		//if (color != 0)//alpha channel black
			/*XDrawLine(*dpy, *w, gc,
				offsetx+(int)xx,
				offsety+(int)yy,
				offsetx+(int)xx,
				offsety+(int)yy);
			*//*XDrawLine(*dpy, *w, gc,
				offsetx+(int)prot[0],
				offsety+(int)prot[1],
				offsetx+(int)prot[0],
				offsety+(int)prot[1]);
			*/
			//model.addpoint(Point(prot[0],prot[1],prot[2],color));
			model.addpoint(Point(xx*_alpha,yy*_beta,zz*_gamma,color));
			}
		}
	}		
	return 0;
}
int SpiderTexture::initconeorcylindersinkY(SpiderModel& model)
{
	_alpha = 1;//4;
	_beta = 1;//10;
	_gamma = 1;//10;
	double X = 1;
	double Y = 10;
	for (int yy = -_legh; yy < _legh; yy ++) {
	for (int xx = -_legw; xx < _legw; xx ++) {
	for (int zz = -_legz; zz < _legz; zz ++) {
			//_beta *= 0.9;
//		for (int xx = 0; xx < _legw*Y/X; xx ++) { 
			//Point pt(1,pty,ptz);
			//unsigned long color = 65000;
			unsigned long color = 0xff;//FIXME1 get_xpmimage().getpixel((int)(xx*X/Y)%_w, (int)(yy*X/Y)%_h);
		
			//model.addpoint(Point(prot[0],prot[1],prot[2],color));
			//model.addpoint(Point(xx*_alpha,yy*_beta,zz*_gamma,color));
			model.addpoint(Point(xx,yy,zz,color));
			}
		}
		X += 0.1;
		Y -= 0.1;
	}		
	return 0;
}
int SpiderTexture::initconeorcylindersmallpatternY(SpiderModel& model)
{
	_alpha = 1;//4;
	_beta = 1;//10;
	_gamma = 1;//10;
	double X = 1;
	double Y = 10;
	double r = 10;
	for (int yy = -_legh; yy < _legh; yy ++) {
	for (int xx = -_legw; xx < _legw; xx ++) {
	for (int zz = -_legz; zz < _legz; zz ++) {
			//_beta *= 0.9;
//		for (int xx = 0; xx < _legw*Y/X; xx ++) { 
			//Point pt(1,pty,ptz);
			//unsigned long color = 65000;
			unsigned long color = 0xff;//FIXME1get_xpmimage().getpixel((int)(yy*yy-r*r)%_w, (int)(xx*xx-r*r)%_h);
		
			//model.addpoint(Point(prot[0],prot[1],prot[2],color));
			//model.addpoint(Point(xx*_alpha,yy*_beta,zz*_gamma,color));
			model.addpoint(Point(xx,yy,zz,color));
			}
		}
		X += 0.1;
		Y -= 0.1;
	}		
	return 0;
}
int SpiderTexture::initconeorcylinderditherY(SpiderModel& model)
{
	_alpha = 1;//4;
	_beta = 1;//10;
	_gamma = 1;//10;
	double X = 1;
	double Y = 10;
	double r = 10;
	for (int zz = -_legz; zz < _legz; zz ++) {
	for (int yy = -_legh; yy < _legh; yy ++) {
	for (int xx = -_legw; xx < _legw*_alpha; xx ++) {
			_alpha *= 0.9;
			_beta -= 0.9;
//		for (int xx = 0; xx < _legw/X; xx ++) { 
			//Point pt(1,pty,ptz);
			//unsigned long color = 65000;
			unsigned long color = 0xff;//FIXME1get_xpmimage().getpixel((int)(xx*_alpha)%_w, (int)(yy*_beta)%_h);
		
			//model.addpoint(Point(prot[0],prot[1],prot[2],color));
			//model.addpoint(Point(xx*_alpha,yy*_beta,zz*_gamma,color));
			model.addpoint(Point(sqrt(yy*yy+zz*zz-r*r),sqrt(xx*xx+zz*zz-r*r),sqrt(yy*yy+xx*xx-r*r),color));
			}
		}
	}		
	return 0;
}
int SpiderTexture::initconeorcylinderdither2Y(SpiderModel& model)
{
	_alpha = 160;//4;
	_beta = 1;//10;
	_gamma = 1;//10;
	double X = 1;
	double Y = 10;
	double r = 10;
	for (int zz = -_legz; zz < _legz; zz ++) {
	for (int yy = -_legh; yy < _legh; yy ++) {
	for (int xx = -_legw; xx < _legw*_alpha; xx ++) {
			_alpha *= 0.9;
			//_beta -= 0.9;
			//Point pt(1,pty,ptz);
			//unsigned long color = 65000;
			unsigned long color = 0xff;//FIXME1 get_xpmimage().getpixel((int)(xx*_alpha)%_w, (int)(yy*_beta)%_h);
		
			model.addpoint(Point(sqrt(yy*yy+zz*zz-r*r),sqrt(xx*xx+zz*zz-r*r),sqrt(yy*yy+xx*xx-r*r),color));
			}
		}
	}		
	return 0;
}
int SpiderTexture::initconeorcylindergrowY(SpiderModel& model)
{
	_alpha = 160;//4;
	_beta = 1;//10;
	_gamma = 1;//10;
	double X = 1;
	double Y = 10;
	double r = _legh/2;
	for (int zz = -_legz; zz < _legz; zz ++) {
	for (int yy = 0/*-_legh*/; yy < _legh/2; yy ++) {
	for (int xx = -_legw; xx < _legw*_alpha; xx ++) {
			_alpha *= 0.9;
			r /= 2;
			//_beta -= 0.9;
			//Point pt(1,pty,ptz);
			//unsigned long color = 65000;
			unsigned long color = 0xff;//FIXME1get_xpmimage().getpixel((int)(xx*_alpha)%_w, (int)(yy*_beta)%_h);
		
			model.addpoint(Point(sqrt(yy*yy+zz*zz-r*r),sqrt(xx*xx+zz*zz-r*r),sqrt(yy*yy+xx*xx-r*r),color));
			}
		}
	}		
	return 0;
}
//draw a diagonal spider leg
int SpiderTexture::initspiderleg(SpiderModel& model)
{
	model.empty_points();

	double r = 10;//_legh/4;
	//double fracx = _w/_legw/2;
	//double fracy =_h/_legh/2;
	for (int zz = -_legz; zz < _legz; zz ++) {
	for (int yy = 0; yy < _legh; yy++/*yy += fracy*/) {
	for (int xx = -_legw; xx < _legw/**_alpha*/; xx++/*xx += fracx*/) {
			//r /= 2;
			Uint32 color = 0xff;//FIXME1 get_xpmimage().getpixel((int)(xx*fracx)%_w, (int)(yy*fracy)%_h);
	/*	
        		Matrix3 rotmx = ray3d::rotatex(thetax);
        		Matrix3 rotmy = ray3d::rotatey(thetay);
        		Matrix3 rotmz = ray3d::rotatez(thetaz);
			thetax += 0.01;
			thetay += 0.01;
			thetaz += 0.01;
			Vector3 prot(sqrt(yy*yy+zz*zz),yy,sqrt(yy*yy+xx*xx-r*r));
			prot = rotmz*prot;
			prot = rotmy*prot;
			//prot = rotmx*prot;
			Point p(prot[0],prot[1],prot[2],color);
	*/
			model.addpoint(Point(sqrt(yy*yy+zz*zz-r*r),yy,sqrt(yy*yy+xx*xx-r*r),color));
			//model.addpoint(p);
			}
		}
	}		
	return 0;
}

int SpiderTexture::initclover(SpiderModel& model)
{
	//model.empty_points();

	double r = 10;//_legh/4;
	//double fracx = _w/_legw/2;
	//double fracy =_h/_legh/2;
	for (int zz = -_legz; zz < _legz; zz ++) {
	for (int yy = 0; yy < _legh; yy++/*yy += fracy*/) {
	for (int xx = -_legw; xx < _legw/**_alpha*/; xx++/*xx += fracx*/) {
			//r /= 2;
			Uint32 color = 0xff;//FIXME1get_xpmimage().getpixel((int)(xx*fracx)%_w, (int)(yy*fracy)%_h);
		
        		Matrix3 rotmx = ray3d::rotatex(_thetax);
        		Matrix3 rotmy = ray3d::rotatey(_thetay);
        		Matrix3 rotmz = ray3d::rotatez(_thetaz);
			_thetax += 0.01;
			_thetay += 0.01;
			_thetaz += 0.01;
			Vector3 prot(sqrt(yy*yy+zz*zz),yy,sqrt(yy*yy+xx*xx-r*r));
			//FIXME1 tully prot = rotmz*prot;
			//prot = rotmy*prot;
			//prot = rotmx*prot;
			Point p(prot[0],prot[1],prot[2],color);
	
			//model.addpoint(Point(sqrt(yy*yy+zz*zz-r*r),yy,sqrt(yy*yy+xx*xx-r*r),color));
			model.addpoint(p);
			}
		}
	}		
	return 0;
}
//enlarge with _alpha, _beta and rotate with thetax thetay,thetaz matrices
int SpiderTexture::rotatemodel(SpiderModel& model)
{
	SpiderModel retmodel;//FIXME 
	retmodel.empty_points();//FIXME loads initdraw again
	int i = 0;
	for (std::vector<Point>::iterator vi = model.get_points().begin(); vi != model.get_points().end(); vi++) {
			
			Uint32 color = 0xff;//FIXME1get_xpmimage().getpixel((int)pt.get_x(), (int)pt.get_y());
        	Matrix3 rotmx = ray3d::rotatex(_thetax);
        	Matrix3 rotmy = ray3d::rotatey(_thetay);
        	Matrix3 rotmz = ray3d::rotatez(_thetaz);
			_thetax += 0.1;
			_thetay += 0.1;
			_thetaz += 0.1;
			Vector3 prot((*vi).get_x(),(*vi).get_y(),(*vi).get_z());
			//prot = rotmz*prot;
			//prot = rotmy*prot;
			//prot = rotmx*prot;
			Point p(prot.get_x(),prot.get_y(),prot.get_z(),color);//FIXME1 color
			//if (color != 0)//alpha channel black
			retmodel.addpoint(p);
		
	}
	model.empty_points();
	model.set_points(retmodel.get_points());
	return 0;
}
}
