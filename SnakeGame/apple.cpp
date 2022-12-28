#include <iostream>
#include "apple.h"
#include "board.h"


void apple::spawnApple()
{
	boardObject.gameBoard[positionX][positionY] = 'O';
}

void apple::generateRandomPosition()
{
	srand(time(NULL));
	positionX = std::rand() % 25;
	positionY = std::rand() % 25;
}


void apple::printScore()
{
	appleScore++;
	std::cout << "Your current score: " << appleScore;
}

void apple::printBestScore()
{
	if(appleScore > bestAppleScore)
		bestAppleScore = appleScore;

	std::cout << "Your best score: " << bestAppleScore;
}