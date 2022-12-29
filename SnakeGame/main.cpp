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

	boardObject.printBoard();

	while (gameRunning)
	{
		snakeObject.spawnSnake();
		appleObject.spawnApple();
		snakeObject.move();
		if (snakeObject.kill())
			gameRunning = 0;
		snakeObject.changeDirection();
		snakeObject.eatApple();
	}
}