#pragma once
class board
{
public:
	char gameBoard[25][25];
	void fillBoard();
	void printBoard();
	void generateRandomApple();
	
};

extern board boardObject;