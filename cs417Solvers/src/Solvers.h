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
void   guassSeidel2(double** A, double* b, double *x, const int& r, const int& c);

double* SOR(double** a, double* b, double* x, const int& r, const int& c);

//Post: allocates matrix of size rxc (All values are 0).
double** emptyMatrix(const int& r, const int& c);
//Post: allocates vector of size rx1 (All values are 0).
double* emptyVector(const int& r);

void randomMatrix();
void randomMatrix(int, int);

void printMatrix(double ** A, int r, int c);
void printMatrix(std::ostream& out, double** A, int r, int c);
void printVector(const double * b, int r);
void printVector(std::ostream& out, const double* b, int r);

double error(const double* bGuess, const double* bAct, int row);

void freeMatrix(double** A, const int& r);
void freeVector(double* b);

void MaxtrixTranspose(double** A, const int& r, const int& c);
double dotProduct(double* b, double* x, const int& r);
double** crossProduct(double* b, double * x, const int& r);
double* matVec(double** A, double* x, int r, int c);
double** matMat(double** A, double** M, const int& r);

void rowSwap(double** A, const int& swap1, const int& swap2);
void scalar(double** A, const double& scalar, const int& r, const int& c);
void scalar(double* b,const double& scalar, const int& r);
void addRows(double** A, const int& replacedRow, const int& addedRow, const int& c);


#endif /* SOLVERS_H_ */
