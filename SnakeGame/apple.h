#pragma once
class apple
{
private:
	int appleScore = 0;
	int bestAppleScore = 0;
public:
	int positionX = 30; //deafult position for X
	int positionY = 9;	//deafult position for Y
	void spawnApple();
	void generateRandomPosition();
	void printScore();
	void addScore();
	void printBestScore();
	void reset();
};

extern apple appleObject;

