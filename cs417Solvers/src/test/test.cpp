/*
 * test.cpp
 *
 *  Created on: Mar 22, 2015
 *      Author: Matthew
 */
#include <iostream>
#include "C:\Users\Matthew\git\cs417\cs417Solvers\src\Solvers.h"
const double ERROR = .00001;

/*
 * This will only work on my computer.
 * To resolve, change the include path for Solvers.h.
 */
int main()
{
	double x = 1;

	for(int i = 0; i < 100; ++i)
	{
		x= x - newton(f(x), fprime(x));
		std::cout << x << '\n';
	}
	return 0;
}
