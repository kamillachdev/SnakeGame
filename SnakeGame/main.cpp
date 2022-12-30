#include <iostream>
#include <windows.h>
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
	bool waitForPressedKey = 0;

	boardObject.printBoard();
	while (true)
	{
		waitForPressedKey = 0;

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

		boardObject.gotoxy(0, 21); cout << "Right arrow - play again; Escape - quit;";

		while (!waitForPressedKey)
		{
			if (GetAsyncKeyState(VK_ESCAPE))
			{
				return 0;
			}
			else if (GetAsyncKeyState(VK_RIGHT))
			{
				waitForPressedKey = 1;
				gameRunning = 1;
				boardObject.gotoxy(0, 21); cout << "                                           ";
				snakeObject.reset();
				appleObject.reset();
			}
		}
	}
}