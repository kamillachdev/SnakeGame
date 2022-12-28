#include <iostream>
#include <windows.h>
#include "snake.h"
#include "board.h"

using std::cout;

void snake::spawnSnake()
{
	int tempPositionY = positionY;
	for (int i = 0; i < snakeLength; i++)
	{
		boardObject.gameBoard[positionX][tempPositionY] = '@';
		tempPositionY--;
	}
}

void snake::changeDirection()
{
	if (GetAsyncKeyState(VK_UP))
	{
		direction = 1;
	}
	else if (GetAsyncKeyState(VK_RIGHT))
	{
		direction = 2;
	}
	else if (GetAsyncKeyState(VK_DOWN))
	{
		direction = 3;
	}
	else if (GetAsyncKeyState(VK_LEFT))
	{
		direction = 4;
	}
}

void snake::move()
{
	switch (direction)
	{
	case 1:
		positionX--;
		break;
	case 2:
		positionY++;
		break;
	case 3:
		positionX++;
		break;
	case 4:
		positionY--;
		break;
	}
}