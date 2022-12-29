#include <iostream>
#include <windows.h>
#include "snake.h"
#include "board.h"
#include "apple.h"

using std::cout;

void snake::spawnSnake()
{
	int tempPositionX = positionX;
	for (int i = 1; i <= snakeLength; i++)
	{
		boardObject.gotoxy(tempPositionX, positionY); cout << '@';
		tempPositionX--;
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
		positionY++;
		break;
	case 2:
		positionX++;
		break;
	case 3:
		positionY--;
		break;
	case 4:
		positionX--;
		break;
	}
}


void snake::eatApple()
{
	if (positionX == appleObject.positionX && positionY == appleObject.positionY)
	{
		appleObject.printScore();
	}
}

bool snake::kill()
{
	if (positionX >= 1 && positionX < 40 && positionY >= 1 && positionY <20)
	{
		boardObject.gotoxy(7, 20); appleObject.printScore();
		return false;
	}
	else
	{
		boardObject.gotoxy(7, 20); cout << "Game over! "; appleObject.printBestScore();
		return true;
	}
}
