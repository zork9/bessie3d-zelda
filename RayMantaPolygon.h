/*
 Copyright (C) Johan Ceuppens 2011
*/
#ifndef _RAY_POLYGON_H_
#define _RAY_POLYGON_H_
#include <vector>
#include "RayMantaPoint.h"
#include "SDL.h"

namespace ray3d {

typedef std::vector<Point> PolygonPoints;

class Polygon {
public:
	Polygon() : _points() {}
	Polygon(PolygonPoints const& v) : _points(v) {}
	virtual ~Polygon() {}

	virtual int draw(SDL_Surface *screen);
	virtual void add(Point const& p) { _points.push_back(p); }
	virtual int size() { return _points.size(); }
protected:
	PolygonPoints _points;

	

public:
	Polygon operator+(Point const& p) { _points.push_back(p); return *this; }
	Polygon operator+=(Point const& p) { _points.push_back(p); return *this; }
	void operator-(Point const& p) { for (PolygonPoints::iterator vi = _points.begin(); vi != _points.end(); vi++) { if ((*vi) == p) { _points.erase(vi); break; }  } }
	Polygon operator=(Point const& p) { _points.push_back(p); return *this; }
	Point operator[](int index) { return _points[index]; }

};
}
#endif
