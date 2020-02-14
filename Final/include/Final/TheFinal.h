#ifndef _THEFINAL_H_
#define _THEFINAL_H_

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

//display functions

//draws 3x3 of dots taking in the width and height
void drawGrid(int width, int height);
//tell the user to enter 100 to quit
void quitPrompt();
//show who won and define which player won
void showWinner(int player);

//input functions

//player 1 picks x and returns an x value
int p1pickX();
//player 1 picks y and returns a y value
int p1pickY();
//player 2 picks x and returns an x value
int p2pickX();
//player 2 picks y and returns a y value
int p2pickY();
//quits the game
void quitGame();

//game logic

//checks if any win conditions are satisfied, returns 1 for dub and 0 for loss, takes the game board as a parameter
int checkWin(gs_tictactoe game);
//sets spaces equal to player coords and takes the game board as a parameter
void playGame(gs_tictactoe game);
//prints the board and takes the game board as a parameter
void printBoard(gs_tictactoe game);
//launches the game
int launchTicTacToe();

#endif //_THEFINAL_H_
