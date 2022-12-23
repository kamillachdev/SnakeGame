#pragma once
class snake
{
private:
	int snakeLength = 3; //starting snake length 
	int direction = 4;   //1 - top, 2 - left, 3 - bottom, 4 - right(deafult)
	int positionX = 12;  //start position
	int positionY = 5;	 //start position
public:
	void spawnSnake();
	void changeDirection();
	inline void lengthIncrease();
};

