#include <iostream>
#include "board.h"
#include "snake.h"
#include "apple.h"
using std::cout;

board boardObject;
snake snakeObject;
apple appleObject;

int main()
{
	bool gameRunning = 1;

	while (gameRunning)
	{
		boardObject.fillBoard();
		snakeObject.spawnSnake();
		appleObject.spawnApple();
		boardObject.printBoard();
		system("cls");
		snakeObject.move();
		snakeObject.changeDirection();
		snakeObject.eatApple();
	}
}