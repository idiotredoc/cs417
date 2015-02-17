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
	char choice;
	std::string garb, filename;

	ifstream datid;
	ofstream outid;

	cout << "***CS 417 Solvers***\n";

	do
	{
		cout << "1. Random Matrix\n"
			 << "2. Load Matrix from file\n"
			 << "Enter 'Q' to quit...\n";
		cin >> choice;
		getline(cin, garb);
	}
	while( (choice != '1') && (choice !='2') && (choice !='q') && (choice != 'Q') );

	if(choice == '1')
	{
		cout << "Generating random matrix...\n"
			 << "Saving Matrix to 'randomMatrix.txt...'\n"
			 << "Saving X values to 'X.txt'...\n";
	}
	else if(choice == '2')
	{
		cout << "Enter file name: ";
		cin >> filename;

		datid.open( filename.c_str() );
	}

	return 0;
}
