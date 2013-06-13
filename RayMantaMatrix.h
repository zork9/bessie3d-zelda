/*
 Copyright (C) Johan Ceuppens 2011
*/
#ifndef _RAYMANTA_MATRIX_H_
#define _RAYMANTA_MATRIX_H_
#include <vector>

typedef std::vector<double> PointsVector;
typedef std::vector<PointsVector> PointsMatrix;

class Vector
{
public:
	Vector(){}
	Vector(Vector const& v) { points = const_cast<Vector&>(v).get_points(); }
	Vector(PointsVector const& p){ points = p; }
	virtual ~Vector() {}

	PointsVector get_points() { return points; }
	void add(double d) { points.push_back(d); }
	double get(int index) { return points[index]; }
protected:
	PointsVector points;

public:
	double operator*(Vector const& v);
	Vector& operator=(Vector const& v) { points = const_cast<Vector&>(v).get_points(); return *this; } 
};

class Matrix {

public:
	Matrix() {}
	Matrix(Matrix const& m) { points = const_cast<Matrix&>(m).get_points(); }
	Matrix(PointsMatrix const& p){ points = p; }
	virtual ~Matrix() {}

	PointsMatrix get_points() { return points; }
	void add(PointsVector v) { points.push_back(v); }
	double get(int index, int index2) { return points[index][index2]; }

protected:
	PointsMatrix points;
public:
	Matrix operator*(Matrix const& m);
	Vector operator*(Vector const& v);
};

#endif
