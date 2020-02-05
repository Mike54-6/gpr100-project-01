using namespace std;

#include <iostream>
#include <stdio.h>

#include "GPRO-FW/common.h"

//-----------------------------------------------------------------------------
// DECLARATIONS

#define GS_BATTLESHIP_PLAYERS				2
#define GS_BATTLESHIP_BOARD_WIDTH			10
#define GS_BATTLESHIP_BOARD_HEIGHT			10

enum gs_battleship_space_state
{
	// invalid space state
	gs_battleship_space_invalid = -1,

	// states visible to both players
	gs_battleship_space_open = ' ',			// space is open and unguessed
	gs_battleship_space_miss = 'O',			// space was guessed and missed
	gs_battleship_space_hit = 'X',            // space was guessed and hit
	gs_battleship_space_ship = 'U',           //space is occupied by ship 

	// states hidden from opponent player
	gs_battleship_space_patrol2,		// 2-unit patrol boat
	gs_battleship_space_submarine3,		// 3-unit submarine
	gs_battleship_space_destroyer3,		// 3-unit destroyer
	gs_battleship_space_battleship4,	// 4-unit battleship
	gs_battleship_space_carrier5,		// 5-unit carrier
};
#ifndef __cplusplus
typedef		enum gs_battleship_space_state	gs_battleship_space_state;
#endif	// !__cplusplus

// battleship game state
typedef		unsigned char					gs_battleship_index;
typedef		gs_battleship_space_state		gs_battleship[GS_BATTLESHIP_PLAYERS][GS_BATTLESHIP_BOARD_WIDTH][GS_BATTLESHIP_BOARD_HEIGHT];


#define	GS_VALIDATE_COORDINATE(x,y,z,w,h,d)		(x < w && y < h && z < d)
#define GS_BATTLESHIP_VALID(p,x,y)				GS_VALIDATE_COORDINATE(x,y,p,GS_BATTLESHIP_BOARD_WIDTH,GS_BATTLESHIP_BOARD_HEIGHT,GS_BATTLESHIP_PLAYERS)


inline gs_battleship_space_state gs_battleship_getSpaceState(gs_battleship const game, gs_battleship_index const player, gs_battleship_index const xpos, gs_battleship_index const ypos)
{
	if (GS_BATTLESHIP_VALID(player, xpos, ypos))
		return (game[player][xpos][ypos]);
	return gs_battleship_space_invalid;
}

inline gs_battleship_space_state gs_battleship_setSpaceState(gs_battleship game, gs_battleship_space_state const state, gs_battleship_index const player, gs_battleship_index const xpos, gs_battleship_index const ypos)
{
	if (GS_BATTLESHIP_VALID(player, xpos, ypos))
		return (game[player][xpos][ypos] = state);
	return gs_battleship_space_invalid;
}

inline gs_battleship_index gs_battleship_reset(gs_battleship game)
{
	gs_battleship_index player, xpos, ypos, total;
	for (player = 0; player < GS_BATTLESHIP_PLAYERS; ++player)
		for (xpos = 0; xpos < GS_BATTLESHIP_BOARD_WIDTH; ++xpos)
			for (ypos = 0; ypos < GS_BATTLESHIP_BOARD_HEIGHT; ++ypos)
				game[player][xpos][ypos] = gs_battleship_space_open;
	total = (player * xpos * ypos);
	return total;
}


//-----------------------------------------------------------------------------
// DEFINITIONS

int win = 0;
int P1totalShipsHit = 0;
int P2totalShipsHit = 0;

void placeShips(gs_battleship game, int num, int num2, int player);
void printBoard(gs_battleship game, int player);
void pickShips1(gs_battleship game, int player);
void pickShips2(gs_battleship game, int player);

int launchBattleship()
{
	gs_battleship game_player1;

	cout << "Type 100 at any time to quit" << endl;
	cout << "Player 1 picks coordinates" << endl;
	gs_battleship_reset(game_player1);
	cout << "Pick your patrol boat coords" << endl;
	placeShips(game_player1, 2, 0, 0);
	cout << "Pick your submarine coords" << endl;
	placeShips(game_player1, 3, 0, 0);
	cout << "Pick your destroyer coords" << endl;
	placeShips(game_player1, 3, 0, 0);
	cout << "Pick your battleship coords" << endl;
	placeShips(game_player1, 4, 0, 0);
	cout << "Pick your carrier coords" << endl;
	placeShips(game_player1, 5, 0, 0);
	printBoard(game_player1, 0);

	cout << "Player 2 picks coordinates" << endl;
	cout << "Pick your patrol boat coords" << endl;
	placeShips(game_player1, 2, 0, 1);
	cout << "Pick your submarine coords" << endl;
	placeShips(game_player1, 3, 0, 1);
	cout << "Pick your destroyer coords" << endl;
	placeShips(game_player1, 3, 0, 1);
	cout << "Pick your battleship coords" << endl;
	placeShips(game_player1, 4, 0, 1);
	cout << "Pick your carrier coords" << endl;
	placeShips(game_player1, 5, 0, 1);
	printBoard(game_player1, 1);

	pickShips1(game_player1, 1);

	return 0;
}

void printBoard(gs_battleship game, int player) 
{
	for (int i = 0; i < 10; i++) 
	{
		cout << endl;
		for (int j = 0; j < 10; j++)
		{
			cout << (char)gs_battleship_getSpaceState(game, player, i, j) << ",";
		}
	}
	cout << endl;
}

void placeShips(gs_battleship game, int num, int num2, int player)
{

	for (int i = 0; i < num; i++)
	{
		int x = 0;
		cout << "Pick x coord: ";
		cin >> x;
		if (x == 100)
		{
			exit(0);
		}

		int y = 0;
		cout << "Pick y coord: ";
		cin >> y;
		if (y == 100)
		{
			exit(0);
		}

		gs_battleship_setSpaceState(game, gs_battleship_space_ship, player, x, y);
		x = 0;
		y = 0;
	}
}

void pickShips1(gs_battleship game, int player) 
{
	
	if (win == 0)
	{
		cout << "Take your pick" << endl;
		cout << "Player 1 pick" << endl;

		int x = 0;
		cout << "Pick x coord: ";
		cin >> x;
		if (x == 100)
		{
			exit(0);
		}

		int y = 0;
		cout << "Pick y coord: ";
		cin >> y;
		if (y == 100)
		{
			exit(0);
		}

		char check = (char)gs_battleship_getSpaceState(game, player, x, y);
		if (check == 'U' || check == 'X')
		{
			cout << "HIT" << endl;
			gs_battleship_setSpaceState(game, gs_battleship_space_hit, player, x, y);
			P1totalShipsHit += 1;
			if (P1totalShipsHit == 17)
			{
				cout << "Player 1 wins" << endl;
				win = 1;
				printBoard(game, player);
			}
		}
		else if (check == ' ' || check == 'O')
		{
			cout << "MISS" << endl;
			gs_battleship_setSpaceState(game, gs_battleship_space_miss, player, x, y);
		}

		pickShips2(game, 0);
	}
	else
	{
		cout << "Player two wins!" << endl;
	}
}

void pickShips2(gs_battleship game, int player)
{
	if (win == 0)
	{
		cout << "Take your pick" << endl;
		cout << "Player 2 pick" << endl;

		int x = 0;
		cout << "Pick x coord: ";
		cin >> x;
		if (x == 100)
		{
			exit(0);
		}

		int y = 0;
		cout << "Pick y coord: ";
		cin >> y;
		if (y == 100)
		{
			exit(0);
		}

		char check = (char)gs_battleship_getSpaceState(game, player, x, y);
		if (check == 'U' || check == 'X')
		{
			cout << "HIT" << endl;
			gs_battleship_setSpaceState(game, gs_battleship_space_hit, player, x, y);
			P2totalShipsHit += 1;
			if (P2totalShipsHit == 17)
			{
				cout << "Player two wins!" << endl;
				win = 1;
				printBoard(game, player);
			}
		}
		else if (check == ' ' || check == 'O')
		{
			cout << "MISS" << endl;
			gs_battleship_setSpaceState(game, gs_battleship_space_miss, player, x, y);
		}

		pickShips1(game, 1);
	}
	else
	{
		cout << "Player one wins!" << endl;
	}
}


//-----------------------------------------------------------------------------
