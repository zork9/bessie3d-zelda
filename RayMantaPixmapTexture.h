/*
 Copyright (C) Johan Ceuppens 2011
*/
#ifndef _RAYPIXMAPTEXTURE_H_
#define _RAYPIXMAPTEXTURE_H_


#include<vector>
#include "RayMantaPoint.h"
//#include "RayMantaPixmapImage.h"
#include "RayMantaEngine.h"
#include "RayMantaTexture.h"

namespace ray3d {

typedef std::vector<Texture> TextureVector;
class PixmapTextureModel;

class PixmapTexture : public Texture {
public:
	PixmapTexture () : Texture(0.5,0.5,0.5) {}//Display **dpy, std::string const& filename, double alpha, double beta, double gamma, int w, int h) : Texture(alpha,beta,gamma), _xpmimage(dpy, filename),_w(w),_h(h),_enlargew(w+w*h*alpha),_enlargeh(h+w*h*beta) {}
	virtual ~PixmapTexture() {}

	//virtual int initdraw(PixmapTextureModel& model);
	//virtual int rotatemodel(PixmapTextureModel& model);

/*	virtual int drawsmaller(Display **dpy, Window *w, int offsetx, int offsety, double a, double b);
	virtual int draw3(Display **dpy, Window *w);
	virtual int draw2(Display **dpy, Window *w);
*/	virtual int drawmain(SDL_Surface *screen, int offsetx, int offsety);
/*	virtual int drawcurved(Display **dpy, Window *w,int offsetx, int offsety);
	virtual int drawcurved2(Display **dpy, Window *w,int offsetx, int offsety);
	virtual int drawcurved3(Display **dpy, Window *w,int offsetx, int offsety);
	virtual int drawbig(Display **dpy, Window *w, int offsetx, int offsety);
	virtual int drawbigger(Display **dpy, Window *w, int offsetx, int offsety);
	*/virtual int drawbiggerandrotate(SDL_Surface *screen, int offsetx, int offsety);
/*	//virtual int drawbiggerandrotatemodel(PixmapTextureModel& model);
	virtual int drawenlargeandrotate(Display **dpy, Window *w, int offsetx, int offsety);
	virtual int drawenlargeandrotate2(Display **dpy, Window *w, int offsetx, int offsety);
	virtual int drawsmall(Display **dpy, Window *w, int offsetx, int offsety);
	virtual int drawsmallandrotate(Display **dpy, Window *w, int offsetx, int offsety);
	virtual RayMantaPixmapImage get_xpmimage() { return _xpmimage; }
*/	virtual int get_w() { return _w; }
	virtual int get_h() { return _h; }
protected:

	//virtual int initdraw1(PixmapTextureModel& model);

//	RayMantaPixmapImage _xpmimage;
	int _w,_h;	
	int _enlargew,_enlargeh;

	double thetax,thetay,thetaz;
};

}

#endif
