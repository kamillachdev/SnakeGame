#include <iostream>
#include <cstdlib>
#include "board.h"

void board::fillBoard()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			gameBoard[i][j] = '-';
		}
	}
}

void board::printBoard()
{
	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 25; j++)
		{
			std::cout << gameBoard[i][j] << " ";
		}
		std::cout << std::endl;
	}
}