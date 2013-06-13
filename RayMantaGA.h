/*
 Copyright (C) Johan Ceuppens 2011
*/
#ifndef _GA_H_
#define _GA_H_

#include <vector>
#include <cmath>

typedef std::vector<double > Genes;

class RayMantaGA {
public:
	RayMantaGA() {}
	RayMantaGA(int size) {/*FIXME linux for (int i = 0; i< size; i++) genes.push_back(std::rand());*/ }
//	inline void init(int size) { /* FIXME linux for (int i = 0; i< size; i++) genes.push_back(std::rand());*/ }
	RayMantaGA(Genes g) { genes = g; }
	virtual ~RayMantaGA() {}

	Genes mutate(int index);	
	Genes crossover(int index1, int index2, Genes g);	
	Genes crossover2(int index1, int index2, Genes g);	
	Genes crossoversame(int index1, int index2);	
	Genes crossoversame2(int index1, int index2);	

	Genes get_genes() { return genes; }


	int eventloop(int ngenes);

protected:
	double fitness();
	double fitness2();//inner product
	double fitness3();//linear programming
	double fitness4();//linear programming
 
	Genes genes;
	Genes crossovergenes;
};

#endif
