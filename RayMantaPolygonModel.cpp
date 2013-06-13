/*
 Copyright (C) Johan Ceuppens 2011-2012
*/

#include<fstream>
#include "RayMantaPolygonModel.h"
#include<cstdlib>
#include<cstring>

namespace ray3d {	

int PolygonModel::draw(SDL_Surface *screen)
{

	for (PolygonVector::iterator vi = _polygons.begin(); vi != _polygons.end(); vi++ ) {
		(*vi).draw(screen);
	}
	return 0;
}

int PolygonModel::filein(std::string const& filename)
{
	std::ifstream *ifs = new std::ifstream(filename.c_str());
	PointVector v;
	PointVector pv;
	Polygon poly;	
	for (; !ifs->eof(); ) {
		char *buf = new char[1024];//FIXME fixed size
		char *buf2 = new char[1024];//FIXME fixed size
		char *buf3 = new char[1024];//FIXME fixed size
		memset(buf,0,1024);
		memset(buf2,0,1024);
		memset(buf3,0,1024);
		(*ifs) >> buf;
		if (ifs->eof()) return -1; else (*ifs) >> buf2;
		if (ifs->eof()) return -1; else (*ifs) >> buf3;
		pv.push_back(Point(atof(buf),atof(buf2),atof(buf3)));
		v.push_back(Point(atof(buf),atof(buf2),atof(buf3)));
		poly += Point(atof(buf),atof(buf2),atof(buf3));
		
		/*for (PVec::iterator vi = v.begin(); vi != v.end(); vi++) {
			std::cout<< "*vi="<<(*vi).get_x()<<" buf="<< std::string(buf).c_str() <<std::endl;
			if ((*vi) == Point(atof(buf),atof(buf2),atof(buf3))) {
				_polygons.push_back(poly);
				poly = Polygon();
				v = PVec();
				pv = PVec();
			}
		}*/
		delete [] buf;
		delete [] buf2;
		delete [] buf3;
	}
	_polygons.push_back(poly);

	return 0;
}

int PolygonModel::fileout(std::string const& filename)
{
	char buf[1024];
	std::ofstream *ofs = new std::ofstream(filename.c_str());
	for (int i = 0; i < _polygons.size(); i++)
	for (int j = 0; j < _polygons[i].size(); j++) {
		sprintf(buf, "%e ", (double)(_polygons[i][j][0]));
		(*ofs) << buf; 
		sprintf(buf, "%e ", (double)(_polygons[i][j][1]));
		(*ofs) << buf; 
		sprintf(buf, "%e ", (double)(_polygons[i][j][2]));
		(*ofs) << buf; 
	}	
	return 0;
}
/*
int PolygonModel::raytrace(Display **dpy, Window *w)
{ //FIXME
}

int PolygonModel::dithersunray(Display **dpy, Window *w)
{//FIXME
}
*/
} // namespace ray3d

