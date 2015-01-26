/*
 * solverMenu.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: Vanacore
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include "Solvers.h"
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;

int main()
{
	double *b, * bG;

	b = new double[3];
	b[0] = 1;
	b[1] = 2;
	b[2] = 3;

	bG = new double[3];
	bG[0] = 1.01;
	bG[1] = 1.95;
	bG[2] = 2.99;

	cout << error(bG, b, 3) << endl;
	cout << sqrt( pow(.1, 2) + pow(.05, 2) + pow(.001, 2)) / sqrt(14);

	return 0;
}
