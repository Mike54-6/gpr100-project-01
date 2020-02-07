#include "GPRO-FW/common.h"

using namespace std;
#include <iostream>

void drawGrid(int width, int height)
{

	cout << "Board is " << height << " by " << width << ". Please select your coordinate" << endl;
	for (int i = 0; i < height; i++)
	{
		cout << endl;
		for (int j = 0; j < width; j++)
		{
			cout << ".";
		}
	}
	cout << endl;
}

void quitPrompt()
{
	cout << "Type 100 at any time to quit" << endl;
}

void showWinner(int player) 
{
	if (player == 1) 
	{
		cout << "Player one wins!";
	}
	else if (player == 2)
	{
		cout << "Player two wins!";
	}
}

int p1pickX()
{
	int x;
	cout << "Player 1 pick x coord: ";
	cin >> x;
	return x;
}

int p1pickY()
{
	int y;
	cout << "Player 1 pick y coord: ";
	cin >> y;
	return y;
}

int p2pickX()
{
	int x;
	cout << "Player 2 pick x coord: ";
	cin >> x;
	return x;
}

int p2pickY()
{
	int y;
	cout << "Player 2 pick y coord: ";
	cin >> y;
	return y;
}

void quitGame()
{
	exit(0);
}

int chooseGame()
{
	int temp;
	cout << "Which game would you like to play? Type 1 for tic tac toe, or 2 for battleship" << endl;
	cin >> temp;
	return temp;
}
