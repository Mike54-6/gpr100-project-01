// GPRO-FW-Launcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;

#include <iostream>
#include "GPRO-FW/common.h"

int launchTicTacToe();
int launchBattleship();

int main()
{
	int temp;
	temp = chooseGame();
	if (temp == 1)
	{
		launchTicTacToe();
	}
	else if (temp == 2)
	{
		launchBattleship();
	}
}
