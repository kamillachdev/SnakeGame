#include <iostream>
#include "apple.h"
#include "board.h"

using std::cout;

void apple::spawnApple()
{
	boardObject.gotoxy(positionX, positionY); std::cout << 'O';
}

void apple::generateRandomPosition()
{
	srand(time(NULL));
	positionX = std::rand() % 40;
	positionY = std::rand() % 20;
}


void apple::printScore()
{
	std::cout << "Your current score: " << appleScore << "                 ";
}

void apple::addScore()
{
	appleScore++;
}

void apple::printBestScore()
{
	if(appleScore > bestAppleScore)
		bestAppleScore = appleScore;

	std::cout << "Your best score: " << bestAppleScore;
}

void apple::reset()
{
	boardObject.gotoxy(positionX, positionY); cout << '-'; //remove old apple form the board
	appleScore = 0;
	positionX = 30;
	positionY = 9;
}