/*
 * Solvers.h
 *
 *  Created on: Jan 24, 2015
 *      Author: Vanacore
 */

#ifndef SOLVERS_H_
#define SOLVERS_H_

double * jacobi(double** A, double* b, double* x, const int& r, const int& c);

void randomMatrix();
void randomMatrix(int, int);

void printMatrix(double ** A, int r, int c);
void printMatrix(double * b, int r);



#endif /* SOLVERS_H_ */
