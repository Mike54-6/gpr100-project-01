#include "Final/TheFinal.h"

using namespace std;
#include <iostream>

//draws 3x3 of dots
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

//tell the user to enter 100 to quit
void quitPrompt()
{
	cout << "Type 100 at any time to quit" << endl;
}

//show who won
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

//player 1 picks x
int p1pickX()
{
	int x;
	cout << "Player 1 pick x coord: ";
	cin >> x;
	return x;
}

//player 1 picks y
int p1pickY()
{
	int y;
	cout << "Player 1 pick y coord: ";
	cin >> y;
	return y;
}

//player 2 picks x
int p2pickX()
{
	int x;
	cout << "Player 2 pick x coord: ";
	cin >> x;
	return x;
}

//player 2 picks y
int p2pickY()
{
	int y;
	cout << "Player 2 pick y coord: ";
	cin >> y;
	return y;
}

//quits the game
void quitGame()
{
	exit(0);
}

inline gs_tictactoe_space_state gs_tictactoe_getSpaceState(gs_tictactoe const game, gs_tictactoe_index const xpos, gs_tictactoe_index const ypos)
{
	if (GS_TICTACTOE_VALID(xpos, ypos))
		return (game[xpos][ypos]);
	return gs_tictactoe_space_invalid;
}

inline gs_tictactoe_space_state gs_tictactoe_setSpaceState(gs_tictactoe game, gs_tictactoe_space_state const state, gs_tictactoe_index const xpos, gs_tictactoe_index const ypos)
{
	if (GS_TICTACTOE_VALID(xpos, ypos))
		return (game[xpos][ypos] = state);
	return gs_tictactoe_space_invalid;
}

inline gs_tictactoe_index gs_tictactoe_reset(gs_tictactoe game)
{
	gs_tictactoe_index xpos, ypos, total;
	for (xpos = 0; xpos < GS_TICTACTOE_BOARD_WIDTH; ++xpos)
		for (ypos = 0; ypos < GS_TICTACTOE_BOARD_HEIGHT; ++ypos)
			game[xpos][ypos] = gs_tictactoe_space_open;
	total = (xpos * ypos);
	return total;
}

//checks if any win conditions are satisfied
int checkWin(gs_tictactoe game)
{
	if ((char)game[0][0] == (char)game[1][0] && (char)game[1][0] == (char)game[2][0])
	{
		if ((char)game[0][0] > 0 && (char)game[1][0] > 0 && (char)game[2][0] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if ((char)game[0][1] == (char)game[1][1] && (char)game[1][1] == (char)game[2][1])
	{
		if ((char)game[0][1] > 0 && (char)game[1][1] > 0 && (char)game[2][1] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if ((char)game[0][2] == (char)game[1][2] && (char)game[1][2] == (char)game[2][2])
	{
		if ((char)game[0][2] > 0 && (char)game[1][2] > 0 && (char)game[2][2] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if ((char)game[0][0] == (char)game[0][1] && (char)game[0][1] == (char)game[0][2])
	{
		if ((char)game[0][0] > 0 && (char)game[0][1] > 0 && (char)game[0][2] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if ((char)game[1][0] == (char)game[1][1] && (char)game[1][1] == (char)game[1][2])
	{
		if ((char)game[1][0] > 0 && (char)game[1][1] > 0 && (char)game[1][2] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if ((char)game[2][0] == (char)game[2][1] && (char)game[2][1] == (char)game[2][2])
	{
		if ((char)game[2][0] > 0 && (char)game[2][1] > 0 && (char)game[2][2] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if ((char)game[0][0] == (char)game[1][1] && (char)game[1][1] == (char)game[2][2])
	{
		if ((char)game[0][0] > 0 && (char)game[1][1] > 0 && (char)game[2][2] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else if ((char)game[2][0] == (char)game[1][1] && (char)game[1][1] == (char)game[0][2])
	{
		if ((char)game[2][0] > 0 && (char)game[1][1] > 0 && (char)game[0][2] > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

//sets spaces equal to player coords
void playGame(gs_tictactoe game)
{
	int win = 0;

	do
	{
		int x;
		x = p1pickX();
		if (x == 100)
		{
			quitGame();
		}

		int y;
		y = p1pickY();
		if (y == 100)
		{
			quitGame();
		}

		int check = gs_tictactoe_getSpaceState(game, x, y);

		if (check != gs_tictactoe_space_open)
		{
			playGame(game);
		}
		else
		{
			gs_tictactoe_setSpaceState(game, gs_tictactoe_space_x, x, y);
		}

		win = checkWin(game);

		cout << "\n\n\tTic Tac Toe\n\n";

		cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
		cout << endl;

		printBoard(game);

		if (win == 1)
		{
			showWinner(1);
			break;
		}

		x = p2pickX();

		y = p2pickY();

		check = gs_tictactoe_getSpaceState(game, x, y);

		if (check != gs_tictactoe_space_open)
		{
			playGame(game);
		}
		else
		{
			gs_tictactoe_setSpaceState(game, gs_tictactoe_space_o, x, y);
		}

		win = checkWin(game);

		//system("cls");
		cout << "\n\n\tTic Tac Toe\n\n";

		cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;
		cout << endl;

		printBoard(game);


		if (win == 1)
		{
			showWinner(2);
			break;
		}

	} while (win != 1);
}

//prints the board
void printBoard(gs_tictactoe game)
{
	cout << "     |     |     " << endl;
	cout << "  " << (char)gs_tictactoe_getSpaceState(game, 0, 0) << "  |  " << (char)gs_tictactoe_getSpaceState(game, 1, 0) << "  |  " << (char)gs_tictactoe_getSpaceState(game, 2, 0) << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << (char)gs_tictactoe_getSpaceState(game, 0, 1) << "  |  " << (char)gs_tictactoe_getSpaceState(game, 1, 1) << "  |  " << (char)gs_tictactoe_getSpaceState(game, 2, 1) << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << (char)gs_tictactoe_getSpaceState(game, 0, 2) << "  |  " << (char)gs_tictactoe_getSpaceState(game, 1, 2) << "  |  " << (char)gs_tictactoe_getSpaceState(game, 2, 2) << endl;

	cout << "     |     |     " << endl << endl;
}

//launches the game
int launchTicTacToe()
{

	gs_tictactoe game;// = { 0 };

	gs_tictactoe_reset(game);
	quitPrompt();
	drawGrid(3, 3);
	playGame(game);

	return 0;
}
