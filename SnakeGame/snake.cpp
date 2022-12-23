#include <iostream>
#include "snake.h"
#include "board.h"

using std::cout;

void snake::spawnSnake()
{
	int tempPositonY = positionY;
	for (int i = 0; i < snakeLength; i++)
	{
		boardObject.gameBoard[positionX][tempPositonY] = '@';
		tempPositonY--;
	}
}