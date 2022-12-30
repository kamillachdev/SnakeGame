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
	bool playAgain = 0;

	boardObject.printBoard();
	do
	{
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

		boardObject.gotoxy(6, 21); cout << "Right arrow - play again; Escape - quit;";
		system("pause");
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			return 0;
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			playAgain = 1;
		}
	} while (playAgain);
}