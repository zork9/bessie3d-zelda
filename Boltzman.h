/*
 Copyright (C) Johan Ceuppens 2011
*/
#ifndef _BOLTZMAN_H_
#define _BOLTZMAN_H_
#include <vector>
#include "RayMantaMatrix.h"
#include <cmath>

typedef std::vector<double> Energies;
class Boltzman {
public:
	Boltzman(double n, double t = 10) { k = pow(1.3806502,-23); T = t; N = n; epsilon = 0.5; Z = exp(epsilon/k*t); }
	virtual ~Boltzman() {}
	
	inline double frandomepsilon() { /*epsilon = std::rand(); return exp(-epsilon/k*T);*/ }
	inline double f() { return exp(-epsilon/k*T); }
	//Boltzman statistics (2 functions)
	inline double f2(double N, Energies egs, double eps, double t); 
	inline double fz(double N, int i, Energies egs, double eps, double t); 
	virtual Matrix generateboltzmanmatrix(Boltzman const& b, int cols, int rows);

protected:
	double N,Z,k,T,epsilon;
};

#endif
