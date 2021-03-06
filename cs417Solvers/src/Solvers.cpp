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
#include <cmath>
#include "Solvers.h"

double * jacobi(double** A, double* b, double* x, const int& r, const int& c )
{
	double* xk1;
	xk1 = emptyVector(c);

	double total, lowerC, upperC;

	//i loop
	for(int i=0; i<c; ++i)
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

void jacobi2(const double** A, const double* b, double* x, const int& r, const int& c)
{

	double* xk1;
	xk1 = emptyVector(c);

	double total, lowerC, upperC;

	//i loop
	for(int i=0; i<c; ++i)
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

	freeVector(x);
	x = xk1;
}

double* guassSeidel(double** A, double* b, double *x, const int& r, const int& c)
{
	double total, lowerC, upperC;

	//i loop
	for(int i=0; i<c; ++i)
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
		x[i] = total / A[i][i];
	}

	return x;
}

void   guassSeidel2(double** A, double* b, double *x, const int& r, const int& c)
{
	double total, lowerC, upperC;

		//i loop
		for(int i=0; i<c; ++i)
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
			x[i] = total / A[i][i];
		}
}

double* SOR(double** A, double* b, double* x, const int& r, const int& c)
{
	double* xk1;
	double total, lowerC, upperC, w;

	w = 1.4;

	xk1 = emptyVector(c);

	for(int i =0; i < c; ++i)
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

		xk1[i] = (1-w)*x[i] + ( (w/A[i][i]) * total );

	}


	return xk1;
}

double* gaussianElimination(double** A, double* b, const int& ROW, const int& COL)
{
	double* x;
	x = emptyVector(COL);
	double sum = 0;
	for(int i = ROW-1; i >=0; --i)
	{
		sum = 0;
		for(int j = i+1; j < ROW; ++j)
		{
			sum += A[i][j] * x[j];
		}

		x[i] = b[i] - sum;
	}
	return x;
}

double newton(const double& f, const double& fp)
{
	return f/fp;
}

double** emptyMatrix(const int& r, const int& c)
{
	double** A;
	A = new double* [r];
	for(int i = 0; i < r; ++i)
	{
		A[i] = new double [c];
		for(int j = 0; j < c; ++j)
		{
			A[i][j] = 0.0;
		}
	}

	return A;
}
double* emptyVector(const int& r)
{
	double* b;
	b = new double[r];
	for(int i = 0; i < r; ++i)
	{
		b[i] = 0.0;
	}

	return b;
}

void randomMatrix()
{

}

void randomMatrix(int r, int c)
{
	double ** A, * b, *x;
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
			value = rand() % 100 + 1;
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
		value = rand() % 100 + 1;
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

	freeMatrix(A, r);
	freeVector(b);
	freeVector(x);

	out.close();
}


void printMatrix(double ** A, int r, int c)
{
	//std::cout << "Matrix:\n";
	for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; ++j)
		{
			std::cout << A[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

void printMatrix(std::ostream& out, double** A, int r, int c)
{
	//out << "Matrix:\n";
	for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; ++j)
		{
			out << A[i][j] << ' ';
		}
		out << '\n';
	}
}

void printVector(const double * b, int r)
{
	//std::cout << "Vector:\n";
	for(int i = 0; i < r; ++i)
	{
		std::cout << b[i] << '\n';
	}
}

void printVector(std::ostream& out, const double* b, int r)
{
	//out << "Vector:\n";
	for(int i = 0; i < r; ++i)
	{
		out << b[i] << '\n';
	}
}

double error(const double* bGuess, const double* bAct, int row)
{
	double bGbA,bA, error;
	error = bGbA = bA = 0;

	for(int i = 0; i < row; ++i)
	{
		bA += pow(bAct[i], 2);

		bGbA = bGuess[i] - bAct[i];
		error += pow(bGbA, 2);
	}
	bA = sqrt(bA);
	error = sqrt(error) / bA;

	return error;
}


void freeMatrix(double** A, const int& r)
{
	for(int i = 0; i < r; ++i)
	{
		delete [] A[i];
	}
	delete [] A;
}

void freeVector(double* b)
{
	delete [] b;
}



void MaxtrixTranspose(double** A, const int& r, const int& c)
{
	double ** Atrans, ** temp;
	Atrans = emptyMatrix(r, c);
	for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; ++j)
		{
			Atrans[c][r] = A[r][c];
		}
	}
	temp = A;
	A = Atrans;
	freeMatrix(temp, r);

}

double dotProduct(double* b, double* x, const int& r)
{
	double scalar = 0.0;
	for(int i = 0; i < r; ++i)
	{
		scalar += b[i] * x[i];
	}

	return scalar;
}

double** crossProduct(double* b, double * x, const int& r)
{


	return NULL;
}


double* matVec(double** A, double* x, int r, int c)
{
	double *b;
	b = emptyVector(r);
	for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; ++j)
		{
			b[i] += A[i][j] * x[j];
		}
	}

	return b;
}

//Pre: assumes NxN matrix.
double** matMat(double** A, double** M, const int& r)
{
	double** newMat = emptyMatrix(r, r);
	for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < r; ++j)
		{
			for(int k = 0; k < r; ++k)
			{
				newMat[i][j] += A[i][k] * M[k][j];
			}
		}
	}

	return newMat;
}


void rowSwap(double** A, const int& swap1, const int& swap2)
{
	double* temp = A[swap1-1];
	A[swap1-1] = A[swap2-1];
	A[swap2-1] = temp;
}

void scalar(double** A, const double& scalar, const int& r, const int& c)
{
	for(int i = 0; i < r; ++i)
	{
		for(int j = 0; j < c; ++j)
		{
			A[i][j] *= scalar;
		}
	}
}
void scalar(double* b, const double& scalar, const int& r)
{
	for(int i = 0; i < r; ++i)
	{
		b[i] *= scalar;
	}
}
void addRows(double** A, const int& replacedRow, const int& addedRow, const int& c)
{
	for(int i = 0; i < c; ++i)
	{
		A[replacedRow-1][i] += A[addedRow-1][i];
	}
}

//This will require much more thought. Be back later. Do not call this function.
void upperTriangular(double** A, double* b, const int& r, const int& c)
{
	double scale = 1;

	for(int col = 0; col < c; ++col)
	{
		for(int row = 0; row < r; ++row)
		{
			//Swap for a non-zero row at index A[row][col]
			if(A[row][col] == 0)
			{
				for(int k = row+1; k < r; ++k)
				{
					if(A[k][col] != 0)
					{
						rowSwap(A, row+1, k+1);
						break;
					}
				}
			}

			//START THE ROW OPERATIONS!
			scale = 1/A[row][col];
			scalar(A[row+1], scale, c);



		}
	}
}

//Redefine these functions as needed
double f(const double& x)
{
	return std::pow(x, 3) + std::pow(x, 2) + x;
}

double fprime(const double& x)
{
	return 3*(std::pow(x, 2)) + 2*(x);
}




