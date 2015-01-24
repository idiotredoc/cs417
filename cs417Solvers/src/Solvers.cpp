/*
 * Solvers.cpp
 *
 *
 *  Created on: Jan 24, 2015
 *      Author: Vanacore
 */
#include <stdlib.h> /* srand, rand */
#include <time.h>
#include <fstream>
#include "Solvers.h"

double * jacobi(double** A, double* b, double* x, const int& r, const int& c )
{
	double* xk1;
	xk1 = new double[r];

	for(int i=0; i<r; ++i)
	{
		xk1[i] = 0.0;
	}

	return xk1;
}


void randomMatrix()
{

}

void randomMatrix(int r, int c)
{
	double ** A, * b, *x;
	int ran;
	double value;

	//Allocate A[r][c]
	A = new double* [r];
	for(int i=0; i<r; ++i)
	{
		A[i] = new double [c];
	}

	//Random A values
	srand ( time(NULL) );
	for(int i=0; i<r; ++i)
	{
		for(int j=0; j<c; ++j)
		{
			ran = rand() % 20000 + 1;
			value = ran / 100.00;
			A[i][j] = value;
		}
	}

	//Diagonal Dominate
	value = 0.0;
	for(int i=0; i<r; ++i)
	{
		for(int j=0; j<c; ++j)
		{
			//Abs value added to value
			if(A[i][j] < 0.0)
			{
				value += -1.0 * A[i][j];
			}
			else{
				value += A[i][j];
			}

			A[i][i] = value;
		}
	}

	//Allocate x
	x = new double [r];

	//Random x values
	srand ( time(NULL) );
	for(int i=0; i<r; ++i)
	{
		ran = rand() % 200 + 1;
		value = ran / 100.00;
		x[i] = value;
	}

	//Allocate b
	b = new double [r];

	//A*x = b
	for(int i=0; i<r; ++i)
	{
		value = 0.0;
		for(int j=0; j<c; ++j)
		{
			value+= A[i][j] * x[j];
		}
		b[i] = value;
	}

	//Write to file
	std::ofstream out;
	out.open("randomMatrix.txt");

	//row and col
	out << r << ' ' << c << '\n';

	//A matrix
	for(int i=0; i<r; ++i )
	{
		for(int j=0; j<c; ++j)
		{
			out << A[i][j] << ' ';
		}
		out << '\n';
	}

	//b matrix
	for(int i=0; i<r; ++i)
	{
		out << b[i] << ' ';
	}


	out.close();



}
