/*
 Copyright (C) Johan Ceuppens 2011
*/
#ifndef _RAYTEXTUREMODEL_H_
#define _RAYTEXTUREMODEL_H_

#include<vector>
#include "RayMantaPoint.h"
#include "RayMantaPixmapImage.h"
#include "RayMantaEngine.h"
#include "RayMantaPolygonModel.h"

namespace ray3d {

class TextureModel : public PolygonModel {
public:
	TextureModel () : PolygonModel() {}
	virtual ~TextureModel() {}

	virtual int draw(SDL_Surface *screen);

};

}

#endif
