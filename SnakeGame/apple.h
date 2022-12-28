#pragma once
class apple
{
private:
	int appleScore = 0;
	int bestAppleScore = 0;
public:
	int positionX = 12;
	int positionY = 18;
	void spawnApple();
	void generateRandomPosition();
	void printScore();
	void printBestScore();
};

extern apple appleObject;

