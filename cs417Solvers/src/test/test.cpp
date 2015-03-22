/*
 * test.cpp
 *
 *  Created on: Mar 22, 2015
 *      Author: Matthew
 */
#include <iostream>
#include "C:\Users\Matthew\git\cs417\cs417Solvers\src\Solvers.h"


/*
 * This will only work on my computer.
 * To resolve, change the include path for Solvers.h.
 */
int main()
{
	double** A;
	A = emptyMatrix(2, 2);
	A[0][0] = 1;
	A[0][1] = 1;

	rowSwap(A, 1, 2);
	printMatrix(A, 2, 2);
	addRows(A, 1, 2, 2);
	std::cout << '\n';
	printMatrix(A, 2, 2);
	std::cout << '\n';
	scalar(A[1], 5, 2);
	printMatrix(A, 2, 2);
	return 0;
}
