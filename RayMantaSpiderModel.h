/*
 Copyright (C) Johan Ceuppens 2011-2012
*/
#ifndef _RAYPIXMAPTEXTUREMODELSPIDER_H_
#define _RAYPIXMAPTEXTUREMODELSPIDER_H_


#include<vector>
#include "RayMantaPoint.h"
#include "RayMantaPixmapImage.h"
#include "RayMantaEngine.h"
#include "RayMantaPixmapTextureModel.h"
#include "RayMantaSpiderTexture.h"
#include "RayMantaTexture.h"

namespace ray3d {
class SpiderModel : public Model {
public:
	SpiderModel () : Model(), _spidertexture(1,1,1),_thetax(1),_thetay(1),_thetaz(1) { 	_spidertexture.initdraw(*this); }	
	virtual ~SpiderModel() {}

	virtual int rotateandsetpoints(SDL_Surface *screen, double thetax, double thetay, double thetaz);
	virtual int drawpoints(SDL_Surface *screen, int offsetx, int offsety);
	virtual int drawspider(SDL_Surface *screen, int offsetx, int offsety);
protected:
	SpiderTexture _spidertexture;
	double _thetax, _thetay, _thetaz;
};

}

#endif
