#include <iostream>
#include <cstdlib>
#include <windows.h>
#include "board.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition;

void board::printBoard()
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			gotoxy(i, j); std::cout << '-';
		}
	}
}


void board::gotoxy(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}
