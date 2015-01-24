/*
 * Solvers.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: Vanacore
 */
#include "Solvers.h"

double * jacobi(const double** A, const double* b, const int& r, const int& c )
{
	//Initiate x with random guess
	double *x;
	x = new double [r];
	for(int i=0; i<r; ++i)
	{
		x[i] = b[i];
	}

	/*Solver:
	 * Main Loop
	 */
	for(int i=0; i<r; ++i)
	{
		//Reset totals at the top of each iteration
		double total, totalC;
		total = totalC = 0;

		//Sum L*x (Lower C*x)
		for(int j=0; j<(i-1); ++j)
		{
			totalC += A[i][j] * x[j];
		}

		//Subtract L*x from b.
		total += b[i] - totalC;

		//Sum U*x (Upper C*x)
		totalC = 0;
		for(int j=i; j<r; ++j)
		{
			totalC += A[i][j] * x[j];
		}

		//Subtract U*x from b.
		total += b[i] - totalC;

		// Multiply by D inverse
		// D^-1(b-C*x)
		total = total / (1/A[i][i]);

		//New x[i]
		x[i] = total;

	}

	return x;
}
