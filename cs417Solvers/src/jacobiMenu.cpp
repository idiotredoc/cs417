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

double ERROR = .00001;

int main()
{
	std::ifstream inputFile;
	std::ofstream outputFile;
	std::string iFile, oFile, garb;

	int r, c;
	double** A;
	double *b, *x, *temp, *guessB;

	std::cout << "======CS417: Jacobi";
	std::cout << "======\n\n";

	std::cout << "Enter file name: ";
	std:: cin >> iFile;

	inputFile.open( iFile.c_str() );
	outputFile.open("jacobiOutput.txt");

	inputFile >> r >> c;

	//Allocates the memory.
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

	printMatrix(A, r, c);
	printVector(b, r);

	//Initial Jacobi run
	temp = x;
	x = jacobi(A, b, x, r, c);
	freeVector(temp);

	guessB = matVec(A, x, r, c);
	while(error(guessB, b, r) >= ERROR)
	{
		freeVector(guessB);

		temp = x;
		x = jacobi(A, b, x, r, c);
		freeVector(temp);

		guessB = matVec(A, x, r, c);

		printVector(x, c);
	}


	//Free all the memory
	freeMatrix(A, r);
	freeVector(b);
	freeVector(x);
	freeVector(guessB);

	return 0;
}
