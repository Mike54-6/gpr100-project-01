// GPRO-FW-Launcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;

#include <iostream>
#include "GPRO-FW/common.h"

int launchTicTacToe();
int launchBattleship();

int main()
{
	/*cout << "Which game would you like to play? Type 1 for tic tac toe, or 2 for battleship" << endl;
	int temp;
	cin >> temp;
	if (temp == 1)
	{
		launchTicTacToe();
	}
	else if (temp == 2)
	{
		launchBattleship();
	}*/

	drawGrid(8, 5);
}
