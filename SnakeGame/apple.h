#pragma once
class apple
{
private:
	int appleScore = 0;
	int bestAppleScore = 0;
public:
	int positionX = 30;
	int positionY = 9;
	void spawnApple();
	void generateRandomPosition();
	void printScore();
	void addScore();
	void printBestScore();
};

extern apple appleObject;

