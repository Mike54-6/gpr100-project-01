#ifndef _COMMON_H_
#define _COMMON_H_

//display functions
void drawGrid(int width, int height);
void quitPrompt();
void showWinner(int player);

//input functions
int p1pickX();
int p1pickY();
int p2pickX();
int p2pickY();
void quitGame();
int chooseGame();

#endif //_COMMON_H_
