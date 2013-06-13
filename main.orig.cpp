/*
 Copyright (C) Johan Ceuppens 2011
*/

#include "SDL.h"
#include "Draw2.h"
#include "Draw.h"
#include "3ds/3ds.h"
#include "RayMantaBMPImage.h"
#include "RayMantaPixmapTexture.h"
#include<iostream>
#include<vector>
#include "RayMantaSphereModel.h"
#include "RayMantaSpiderModel.h"
#include "RayMantaPoint.h"
#include "3ds/3ds.h"
#include "Zelda/Player.h"
#include "Zelda/GameEngine.h"

int main(int argc, char *argv[])
{
SDL_Init(SDL_INIT_EVERYTHING);
SDL_Surface *screen  = SDL_SetVideoMode(320, 200, 32, SDL_DOUBLEBUF|SDL_HWSURFACE);

int x = 0;
int y = 0;
int xnum = 0;
int ynum = 0;
/*int i,j;
for (i = 0; i < 200; i++) {
for (j = 0; j < 200; j++) {	
	drawline1Func(&x, &y, &xnum, &ynum, 0.2, 0.3, 1);

	if (x < 800 && y < 600)
		putpixel(screen, x,y,0xff);
}
}*/
int x1 = 100, y1 = 100, x2 = 20, y2 = 100;
drawline(screen, &x1,&y1,&x2,&y2,0xff);

ray3d::SpiderModel spidermodel;
//ray3d::SphereModel spheremodel;
//ray3d::PixmapTexture pixtex;
//pixtex.drawmain(screen, 100, 100);

std::vector<ray3d::Point> vertices3dsfile = load3dsfile_vertices(std::string("example.3ds"));

//RayMantaBMPImage img(std::string("zelda.bmp"));
//img.draw(screen,0,0);

zelda::main::GameEngine gameengine;
SDL_Flip(screen);
//for (;;) {
	//spidermodel.drawspider(screen,100,100);
	//spheremodel.generatesphere(screen,60,60,60);
	//spheremodel.drawpoints(screen);
	//spheremodel.drawsunray(screen);
	gameengine.doLoop(&screen);
	
	
//}
	
return 0;
}
