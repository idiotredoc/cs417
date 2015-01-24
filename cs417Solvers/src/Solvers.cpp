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
#include <iostream>
#include "Solvers.h"

double * jacobi(double** A, double* b, double* x, const int& r, const int& c )
{
	double* xk1;
	xk1 = new double[r];
	for(int i = 0; i < r; ++i)
	{
		xk1[i] = 0.0;
	}

	double total, lowerC, upperC;

	//i loop
	for(int i=0; i<r; ++i)
	{
		total = lowerC = upperC = 0;

		//Sum lowerC
		for(int j = 0; j < i; ++j)
		{
			lowerC += A[i][j] * x[j];
		}

		//Sum upperC
		for( int j = (i+1); j < r; ++j)
		{
			upperC += A[i][j] * x[j];
		}

		//Total for iteration
		total = b[i] - lowerC - upperC;

		//Update xk1[i]
		xk1[i] = total / A[i][i];
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

	//Write X
	std::ofstream out;
	out.open("X.txt");
	for(int i = 0; i < r; ++i)
	{
		out << x[i] << '\n';
	}
	out.close();

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


void printMatrix(double ** A, int r, int c)
{
	std::cout << "Matrix:\n";
	for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; ++j)
		{
			std::cout << A[i][j] << ' ';
		}
	}
}


void printMatrix(double * b, int r)
{
	std::cout << "Matrix:\n";
	for(int i = 0; i < r; ++i)
	{
		std::cout << b[i] << ' ';
	}
}
