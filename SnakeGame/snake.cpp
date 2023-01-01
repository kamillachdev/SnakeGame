#include <iostream>
#include <windows.h>
#include "snake.h"
#include "board.h"
#include "apple.h"

using std::cout;

char head = 'H';
char tail = '@';

void snake::spawnSnake()
{
	int tempPositionX = positionX;
	for (int i = 1; i <= snakeLength; i++)
	{	
		boardObject.gotoxy(tempPositionX, positionY); cout << tail;
		tempPositionX--;
	}
	boardObject.gotoxy(positionX, positionY); cout << head;
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

void snake::move() //here is work
{
	int tempPositionX = positionX;
	int tempPositionY = positionY;
	switch (direction)
	{
	case 1:

		positionY--;
		boardObject.gotoxy(positionX, tempPositionY); cout << tail;
		tempPositionY++;
		boardObject.gotoxy(positionX, positionY); cout << head;
		Sleep(150);
		break;

	case 2:

		positionX++;
		boardObject.gotoxy(tempPositionX, positionY); cout << tail;
		tempPositionX--;
		boardObject.gotoxy(positionX, positionY); cout << head;
		Sleep(150);
		break;

	case 3:

		positionY++;
		boardObject.gotoxy(positionX, tempPositionY); cout << tail;
		tempPositionY--;
		boardObject.gotoxy(positionX, positionY); cout << head;
		Sleep(150);
		break;

	case 4:

		positionX--;
		boardObject.gotoxy(tempPositionX, positionY); cout << tail;
		tempPositionX++;
		boardObject.gotoxy(positionX, positionY); cout << head;
		Sleep(150);
		break;
	}
}


void snake::eatApple()
{
	if (positionX == appleObject.positionX && positionY == appleObject.positionY)
	{
		boardObject.gotoxy(appleObject.positionX, appleObject.positionY); cout << head;
		appleObject.addScore();
		lengthIncrease();
		appleObject.generateRandomPosition();
	}
}

bool snake::killByBorder()
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

bool snake::killBySnake() //here is work
{
	char charOnXY = '-';
	boardObject.gotoxy(positionX, positionY); charOnXY = '@';
	if (charOnXY == tail)
	{
		boardObject.gotoxy(6, 20); cout << "Game over! "; appleObject.printBestScore();
		return true;
	}
	else
	{
		return false;
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