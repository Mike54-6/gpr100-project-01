using namespace std;

#include <iostream>
#include <stdio.h>

#include "Final/TheFinal.h"

//-----------------------------------------------------------------------------
// DECLARATIONS

#define GS_TICTACTOE_PLAYERS					2
#define GS_TICTACTOE_BOARD_WIDTH				3
#define GS_TICTACTOE_BOARD_HEIGHT				3




enum gs_tictactoe_space_state
{
	// invalid space state
	gs_tictactoe_space_invalid = -1,

	// states visible to both players
	gs_tictactoe_space_open,	// space is open
	gs_tictactoe_space_o = char('O'),		// space is taken by O player
	gs_tictactoe_space_x = char('X'),		// space is taken by X player
};
#ifndef __cplusplus
typedef		enum gs_tictactoe_space_state		gs_tictactoe_space_state;
#endif	// !__cplusplus

// tic-tac-toe game state
typedef		unsigned char						gs_tictactoe_index;
typedef		gs_tictactoe_space_state			gs_tictactoe[GS_TICTACTOE_BOARD_WIDTH][GS_TICTACTOE_BOARD_HEIGHT];


#define	GS_VALIDATE_COORDINATE(x,y,w,h)			(x < w && y < h)
#define GS_TICTACTOE_VALID(x,y)					GS_VALIDATE_COORDINATE(x,y,GS_TICTACTOE_BOARD_WIDTH,GS_TICTACTOE_BOARD_HEIGHT)


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


//-----------------------------------------------------------------------------
// DEFINITIONS

int checkWin(gs_tictactoe game);
void playGame(gs_tictactoe game);
void printBoard(gs_tictactoe game);
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

int launchTicTacToe()
{

	gs_tictactoe game;// = { 0 };

	gs_tictactoe_reset(game);
	quitPrompt();
	drawGrid(3, 3);
	playGame(game);

	return 0;
}

int main() {
	launchTicTacToe();
}