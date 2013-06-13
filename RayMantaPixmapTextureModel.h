/*
 Copyright (C) Johan Ceuppens 2011
*/
#ifndef _RAYPIXMAPTEXTUREMODEL_H_
#define _RAYPIXMAPTEXTUREMODEL_H_

#include<vector>
#include "RayMantaPoint.h"
#include "RayMantaPixmapImage.h"
#include "RayMantaEngine.h"
#include "RayMantaTextureModel.h"
#include "RayMantaPixmapTexture.h"
#include "RayMantaTexture.h"

namespace ray3d {
class PixmapTextureModel : public TextureModel {
public:
	PixmapTextureModel (std::string const& filename,int ww, int hh) : TextureModel(), _pixmaptexture(/*filename,1,1,1,ww,hh*/) {}
	virtual ~PixmapTextureModel() {}

	virtual int draw(SDL_Surface *screen, int offsetx, int offsety);
	//virtual int draw2(SDL_Surface *screen);

protected:
	PixmapTexture _pixmaptexture;
	
};

}

#endif
