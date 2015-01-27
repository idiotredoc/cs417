/*
 * Solvers.h
 *
 *  Created on: Jan 24, 2015
 *      Author: Vanacore
 */

#ifndef SOLVERS_H_
#define SOLVERS_H_

class ostream;

double * jacobi(double** A, double* b, double* x, const int& r, const int& c);
void    jacobi2(const double** A, const double* b, double* x, const int& r, const int& c);
double* guassSeidel(double** A, double* b, double *x, const int& r, const int& c);

void randomMatrix();
void randomMatrix(int, int);

void printMatrix(double ** A, int r, int c);
void printMatrix(double * b, int r);
void printMatrix(ostream out, double** A, const int& r, const int& c);
void printMatrix(ostream out, double* b, const int& r);

double error(const double* bGuess, const double* bAct, int row);

#endif /* SOLVERS_H_ */
