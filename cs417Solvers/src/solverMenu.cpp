/*
 * solverMenu.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: Vanacore
 */
/*
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
	double **A, *x, *b;

	int n, m;
	n = m = 1;

	char choice;
	std::string garb, filename;

	ifstream datid;
	ofstream outid;

	cout << "***CS 417 Solvers***\n";

	randomMatrix(2, 3);

	A = emptyMatrix(2, 3);
	x = emptyVector(3);
	b = emptyVector(2);

	datid.open("randomMatrix.txt");
	datid >> n >> m;
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			datid >> A[i][j];
		}
	}

	for(int i = 0; i < n; ++i)
	{
		datid >> b[i];
	}

	printMatrix(A, n, m);
	printVector(b, n);


	do
	{
		cout << "1. Random Matrix\n"
			 << "2. Load Matrix from file\n"
			 << "Enter 'Q' to quit...\n"
			 << ">> ";
		cin >> choice;
		getline(cin, garb);
	}
	while( (choice != '1') && (choice !='2') && (choice !='q') && (choice != 'Q') );

	if(choice == '1')
	{
		cout << "Matrix size(Rows Cols): ";
		cin >> n >> m;

		cout << "Generating random matrix...\n"
			 << "Saving Matrix to 'randomMatrix.txt...'\n"
			 << "Saving X values to 'X.txt'...\n";

		randomMatrix(n, m);
		datid.open("randomMatrix.txt");
		if(!datid)
		{
			cout << "File does not exist...\n";
			cin.get();
			return 1;
		}
	}
	else if(choice == '2')
	{
		cout << "Enter file name: ";
		getline(cin, filename);

		datid.open( filename.c_str() );
		if(!datid)
		{
			cout << "File does not exist...\n";
			cin.get();
			return 1;
		}
	}
	else if( (choice == 'q') || (choice == 'Q') )
	{
		return 1;
	}

	datid >> n >> m;
	A = emptyMatrix(n, m);
	x = emptyVector(m);
	b = emptyVector(n);

	cout << "A:\n";
	for(int i = 0; i < n; ++i)
	{
		for(int j = 0; j < m; ++j)
		{
			datid >> A[i][j];
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}

	cout << "b:\n";
	for(int i = 0; i < n; ++i)
	{
		datid >> b[i];
		cout << b[i]<< endl;
	}

	double* temp;
	temp = x;
	x = jacobi(A, b, x, n, m);
	freeVector(temp);
	printVector(x, m);

	temp = x;
	x = jacobi(A, b, x, n, m);
	freeVector(temp);
	printVector(x, m);

	temp = x;
	x = jacobi(A, b, x, n, m);
	freeVector(temp);
	printVector(x, m);

	temp = x;
	x = jacobi(A, b, x, n, m);
	freeVector(temp);
	printVector(x, m);

	datid.close();

	return 0;
}
*/
