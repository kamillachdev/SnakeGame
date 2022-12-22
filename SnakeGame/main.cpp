#include <iostream>
#include "board.h"

using std::cout;

int main()
{
	bool gameRunning = 1;

	board boardObject;

	while (gameRunning)
	{
		boardObject.fillBoard();
		boardObject.generateRandomApple();
		boardObject.printBoard();
		gameRunning = 0;
	}
}