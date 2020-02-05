#include "GPRO-FW/common.h"

using namespace std;
#include <iostream>

/*int foo(int bar)
{
	return (bar + 1);
}*/

void drawGrid(int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		cout << endl;
		for (int j = 0; j < width; j++)
		{
			cout << "O";
		}
	}
	cout << endl;
}

void drawRow(int width, char content[])
{

}


