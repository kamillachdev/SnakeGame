#include <iostream>
#include "board.h"
#include "snake.h"

using std::cout;

board boardObject;
snake snakeObject;

int main()
{
	bool gameRunning = 1;

	while (gameRunning)
	{
		boardObject.fillBoard();
		boardObject.generateRandomApple();
		boardObject.printBoard();
		system("cls");
		snakeObject.spawnSnake();
		boardObject.printBoard();
		gameRunning = 0;
	}
}