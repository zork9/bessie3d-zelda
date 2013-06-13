/*
 Copyright (C) Johan Ceuppens 2011
*/
#ifndef _RAYTEXTURE_H_
#define _RAYTEXTURE_H_

#include<vector>
#include "RayMantaPoint.h"
#include "RayMantaPixmapImage.h"
#include "RayMantaEngine.h"

namespace ray3d {
class Texture {
public:
	Texture (double alpha, double beta, double gamma) : _alpha(alpha),_beta(beta),_gamma(gamma) {}
	virtual ~Texture() {}

	//virtual int draw();//Display **dpy, Window *w);

	virtual double get_alpha() { return _alpha; }
	virtual double get_beta() { return _beta; }
	virtual double get_gamma() { return _gamma; }

protected:
	double _alpha,_beta,_gamma;//x,y,z scaling factors
};

}

#endif
