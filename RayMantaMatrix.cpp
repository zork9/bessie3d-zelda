/*
 Copyright (C) Johan Ceuppens 2011
*/
#include "RayMantaMatrix.h"

//no test for equal rows/columns	
double Vector::operator*(Vector const& v)
{
	double result = 0;

	for (PointsVector::iterator vi = const_cast<Vector&>(v).get_points().begin(), pi = points.begin(); pi != points.end(); pi++, vi++)
		result += (*pi)*(*vi);

	return result;

}

//no test for equal rows/columns	
Matrix Matrix::operator*(Matrix const& m)
{
//	if (m == *this)
//		return *this;

	PointsMatrix pms;
	PointsVector pvs;	

	for (PointsMatrix::iterator pi = const_cast<Matrix&>(m).get_points().begin(), qi = points.begin(); qi != points.end(); pi++, qi++)
		for (PointsVector::iterator vi = const_cast<PointsVector&>(*pi).begin(), wi = const_cast<PointsVector&>(*qi).begin(); vi != const_cast<PointsVector&>(*pi).end(); wi++, vi++)
			//FIXME transpose
			pvs.push_back((*vi)*(*wi));
		pms.push_back(pvs);
		pvs = PointsVector();	

	return Matrix(pms);
}

Vector Matrix::operator*(Vector const& v)
{
	PointsVector pvs;	

	for (PointsMatrix::iterator pi = get_points().begin(); pi != points.end(); pi++)
		pvs.push_back(const_cast<Vector&>(v) * (*pi));

	return Vector(pvs);	
}

