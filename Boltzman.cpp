/*
 Copyright (C) Johan Ceuppens 2011
*/
#include "Boltzman.h"

double Boltzman::fz(double N, int i, Energies egs, double eps, double t) { 

	double Zresult = 0;

	for (int j = 0; j < egs.size(); j++) {
		Zresult += egs[j]*exp(-eps/k*t);
	}
	return Zresult;
}

double Boltzman::f2(double N, Energies egs, double eps, double t) 
{
	double result = 0;
 
	for (int j = 0; j < egs.size(); j++) {
		result += N*egs[j]*exp(-eps/k*T)/fz(N, j, egs, eps, t);
	}

	return result; 
}
	
Matrix Boltzman::generateboltzmanmatrix(Boltzman const& b, int cols, int rows)
{

	Matrix m;
	Energies egs;
/*
	for (int k = 0; k < rows*cols; k++)
		egs.push_back(std::rand());
*/

	for (int i = 0; i < rows; i++){
		Vector v;
	for (int j = 0; j < cols; j++){
		
		v.add(const_cast<Boltzman&>(b).f2(rows*cols,egs,0.5,10));
	}
		m.add(v.get_points());
	}

	return m;

}

