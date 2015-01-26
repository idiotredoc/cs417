/*
 * solverMenu.cpp
 *
 *  Created on: Jan 24, 2015
 *      Author: Vanacore
 */

#include <iostream>
#include <fstream>
#include <string>
#include "Solvers.h"
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;

int main()
{
	char choice = 0;
	std::string filename;
	bool wrong = true;
	do
	{
		cout << "1. Specify input file...\n" <<
				"2. Randomly generate matrix...\n";
		cin >> choice;
		while(cin)
		{
			cin.get();
		}
		if(choice == '1')
		{
			//Specify file name
			cout << "Filename: ";
			wrong = false;
		}
		else if(choice == '2')
		{
			bool innerWrong = true;
			do
			{
				cout << "Random Size?(Y/N): ";
				cin >> choice;
				while(cin)
				{
					cin.get();
				}

				if(choice == 'Y' || choice == 'y')
				{
					randomMatrix();
				}
				else if(choice == 'N' || choice == 'n')
				{
					int r, c;
					cout << "Row Column: ";
					cin >> r >> c;
					randomMatrix(r, c);
				}
			}while(innerWrong);

			wrong = false;
		}

	}while(wrong);


	return 0;
}
