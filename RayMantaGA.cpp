/*
 Copyright (C) Johan Ceuppens 2011
*/
#include "RayMantaGA.h"
#include <cstdlib>
#include <iostream>

double RayMantaGA::fitness()
{

	double fitn;


	for (Genes::iterator gi = genes.begin(); gi != genes.end(); gi++) {

		fitn += (*gi);

	}

	fitn /= genes.size();

	return fitn;
}

double RayMantaGA::fitness2()
{

	double fitn;

	for (Genes::iterator gi = genes.begin(); gi != genes.end(); gi++) {

		fitn += (*gi);

	}

	fitn * fitn * cos(sqrt(2)/2);

	return fitn;
}

double RayMantaGA::fitness3()
{
	Genes learningrates;
	for (int j = 0; j < genes.size(); j++)
		learningrates[j] = rand();//FIXME random

	double fitn;
	int i = 0;
	for (Genes::iterator gi = genes.begin(); gi != genes.end(); gi++, i++) {
		fitn += (*gi)*learningrates[i];

	}

	fitn /= genes.size();

	return fitn;
}

double RayMantaGA::fitness4()
{
	Genes learningrates;
	for (int j = 0; j < genes.size(); j++)
		learningrates[j] = rand();

	double fitn;
	int i = 0;
	for (Genes::iterator gi = genes.begin(); gi != genes.end(); gi++, i++) {
		if ((*gi) > learningrates[i])
			fitn += (*gi);

	}

	fitn /= genes.size();

	return fitn;
}



Genes RayMantaGA::mutate(int index)
{

	if (genes[index] == 0) genes[index] = 1; else genes[index] = 0;
	return genes;	
}

Genes RayMantaGA::crossover(int index1, int index2, Genes g)
{
	crossovergenes = g;
	//crossover from index1 to index2
	for (int i = index1; i < index2; i++) {
		genes[i] = g[i];
	}
	return genes;
}

Genes RayMantaGA::crossover2(int index1, int index2, Genes g)
{
	crossovergenes = g;
	//crossover from index1 to index2
	for (int i = index1; i < index2; i++) {
		genes[i] = g[i]*genes[i];
	}
	return genes;
}

Genes RayMantaGA::crossoversame(int index1, int index2)
{
	//from index1 to index2
	for (int i = index1; i < index2; i++) {
		genes[i] *= crossovergenes[i];
	}
	return genes;
}

Genes RayMantaGA::crossoversame2(int index1, int index2)
{
	//from index1 to index2
	for (int i = index1; i < index2; i++) {
		genes[i] = genes[i]*genes[i];
	}
	return genes;
}

int RayMantaGA::eventloop(int ngenes)
{
//	init(ngenes);

//	for (;;) {
		long int r = rand();
		int index = r % ngenes;

		mutate(index);
	
		std::cout<<"fitness"<<fitness()<<std::endl;

//	}

	return 0;
}
