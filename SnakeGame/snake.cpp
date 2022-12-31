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
		positionY--;
		boardObject.gotoxy(positionX, positionY); cout << '@';
		for (int i = 1; i <= snakeLength; i++)
		{
			boardObject.gotoxy(positionX - i, positionY + i); cout << "-";
		}
		boardObject.gotoxy(positionX, positionY + snakeLength); cout << "-";

		Sleep(150);
		break;
	case 2:
		positionX++;
		boardObject.gotoxy(positionX, positionY); cout << '@';
		boardObject.gotoxy(positionX - snakeLength, positionY); cout << "-";
		Sleep(150);
		break;
	case 3:
		positionY++;
		boardObject.gotoxy(positionX, positionY); cout << '@';
		boardObject.gotoxy(positionX, positionY - snakeLength); cout << "-";
		Sleep(150);
		break;
	case 4:
		positionX--;
		boardObject.gotoxy(positionX, positionY); cout << '@';
		boardObject.gotoxy(positionX + snakeLength,  positionY); cout << "-";
		Sleep(150);
		break;
	}
}


void snake::eatApple()
{
	if (positionX == appleObject.positionX && positionY == appleObject.positionY)
	{
		appleObject.addScore();
		lengthIncrease();
		appleObject.generateRandomPosition();
	}
}

bool snake::kill()
{
	if (positionX >= 0 && positionX <= 39 && positionY >= 0 && positionY < 20)
	{
		boardObject.gotoxy(6, 20); appleObject.printScore();
		return false;
	}
	else
	{
		boardObject.gotoxy(6, 20); cout << "Game over! "; appleObject.printBestScore();
		return true;
	}
}

inline void snake::lengthIncrease()
{
	snakeLength++;
}


void snake::reset()
{
	for (int i = 1; i <= snakeLength; i++)
	{
		boardObject.gotoxy(positionX - i, positionY); cout << '-'; //removing old snake from the board 
	}
	snakeLength = 3; 
	direction = 2;
	positionX = 10;
	positionY = 9;	 
}