/*
 * Solvers.h
 *
 *  Created on: Jan 24, 2015
 *      Author: Vanacore
 */

#ifndef SOLVERS_H_
#define SOLVERS_H_


double * jacobi(double** A, double* b, double* x, const int& r, const int& c);
void    jacobi2(const double** A, const double* b, double* x, const int& r, const int& c);

double* guassSeidel(double** A, double* b, double *x, const int& r, const int& c);
void   guassSeidel2(double** A, double* b, double *x, const int& r, const int& c);

double* SOR(double** a, double* b, double* x, const int& r, const int& c);

double** emptyMatrix(const int& r, const int& c);
double* emptyVector(const int& r);
void randomMatrix();
void randomMatrix(int, int);

void printMatrix(double ** A, int r, int c);
void printVector(const double * b, int r);

double error(const double* bGuess, const double* bAct, int row);

void freeMatrix(double** A, const int& r);
void freeVector(double* b);

void MaxtrixTranspose(double** A, const int& r, const int& c);



#endif /* SOLVERS_H_ */
