/*
 * jacobiMenu.cpp
 *
 *
 *  Created on: Mar 18, 2015
 *      Author: mvanacor
 */

#include <iostream>
#include <string>
#include <fstream>
#include "Solvers.h"

double ERROR = 10^-5;

int main()
{
	std::ifstream inputFile;
	std::ofstream outputFile;
	std::string iFile, oFile, garb;

	int r, c;
	double** A;
	double *b, *x;

	std::cout << "CS417: Jacobi";
	std::cout << "-------------\n\n";


	std::cout >> "Enter File Name: ";
	std:: cin >> iFile;

	inputFile.open(iFile.c_str() );

	inputFile >> r >> c;
	A = emptyMatrix(r, c);
	b = emptyVector(r);
	x = emptyVector(c);

	//Read A
	for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; ++j)
		{
			inputFile >> A[i][j];
		}
	}

	//Read b
	for(int i = 0; i < r; ++i)
	{
		inputFile >> b[i];
	}

	while(false)
	{

	}


	return 0;
}
