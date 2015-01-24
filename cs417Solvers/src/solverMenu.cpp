/*
 * solverMenu.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: Vanacore
 */

#include <iostream>
#include <fstream>
#include "Solvers.h"

int main()
{
	std::ifstream datid;
	datid.open("randomMatrix.txt");
	double ** A, *b;
	int row, col;

	randomMatrix(5, 5);


	datid >> row >> col;

	A = new double* [row];
	for(int i = 0; i < row; ++i)
	{
		A[i] = new double [col];
		for(int j = 0; j < col; ++j)
		{
			datid >> A[i][j];
		}
	}

	b = new double[row];
	for(int i = 0; i < row; ++i)
	{
		datid >> b[i];
	}



	std::cout << "A:\n";
	for(int i = 0; i < row; ++i)
	{
		for(int j = 0; j < col; ++j)
		{
			std::cout << A[i][j] << ' ';
		}
		std::cout << '\n';
	}

	std::cout << "b:\n";
	for( int i = 0; i < row; ++i)
	{
		std::cout << b[i] << ' ';
	}


	return 0;
}
