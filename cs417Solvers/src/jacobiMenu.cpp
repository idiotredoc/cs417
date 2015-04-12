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
	std::string iFile;

	int r, c;
	double** A;
	double *b, *x, *temp, *guessB;
	int index = 0;

	std::cout << "======CS417: Jacobi";
	std::cout << "======\n\n";

	//Assumes file exist
	std::cout << "Enter file name: ";
	std:: cin >> iFile;

	//Opens files, so the input file better exist.
	inputFile.open( iFile.c_str() );
	outputFile.open("jacobiOutput.txt"); //output file for the jacobi solver.

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

	//Print A and b.
	/*outputFile << "A:\n";
	printMatrix(outputFile, A, r, c);
	outputFile << "b:\n";
	printVector(outputFile, b, r);
	outputFile << '\n';*/

	//Initial Jacobi run
	temp = x;
	x = jacobi(A, b, x, r, c);
	freeVector(temp);
	guessB = matVec(A, x, r, c);

	//Print iteration 0: x, and error!
	outputFile << "============\n";
	outputFile << "Iteration: " << index;
	outputFile << "\n============\n";

	outputFile << "x:\n";
	printVector(outputFile, x, c);

	outputFile << "Error: " << error(guessB, b, r) * 100 << "%\n\n";

	++index;
	while(error(guessB, b, r) >= ERROR)
	{
		freeVector(guessB);

		temp = x;
		x = jacobi(A, b, x, r, c);
		freeVector(temp);

		guessB = matVec(A, x, r, c);

		//Print iteration index: x, and error!
		outputFile << "============\n";
		outputFile << "Iteration: " << index;
		outputFile << "\n============\n";

		outputFile << "x:\n";
		printVector(outputFile, x, c);

		outputFile << "Error: " << error(guessB, b, r) * 100 << "%\n\n";

		++index;
	}


	std::cout << "Results printed to jacobiOutput.txt...\n";
	std::cin.get();
	std::cin.get();


	//Free all the memory
	freeMatrix(A, r);
	freeVector(b);
	freeVector(x);
	freeVector(guessB);

	return 0;
}
