#pragma once
class snake
{
private:
	int snakeLength = 3; //starting snake length 
	int direction = 2;   //1 - top, 2 - right(deafult), 3 - down, 4 - left;
	int positionX = 12;  //start position
	int positionY = 5;	 //start position
public:
	void spawnSnake();
	void changeDirection();
	void move();
	void eatApple();
	inline void lengthIncrease();
};

