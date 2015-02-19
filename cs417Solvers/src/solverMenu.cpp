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
	double **A, *x, *b;

	int n, m;
	n = m = 1;

	char choice;
	std::string garb, filename;

	ifstream datid;
	ofstream outid;

	cout << "***CS 417 Solvers***\n";

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
		cin >> n, m;

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

		datid >> n >> m;
	}
	else if( (choice == 'q') || (choice == 'Q') )
	{
		return 1;
	}

	A = emptyMatrix(n, m);
	x = emptyVector(m);
	b = emptyVector(m);

	for(int i = 0; i < n; ++n)
	{
		for(int j = 0; i < m; ++j)
		{
			datid >> A[i][j];
		}
	}

	for(int i = 0; i < n; ++n)
	{
		b[i];
	}

	return 0;
}
