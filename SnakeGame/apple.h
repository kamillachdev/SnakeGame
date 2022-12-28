#pragma once
class apple
{
private:
	int positionX = 12;
	int positionY = 18;
	int appleScore = 0;
	int bestAppleScore = 0;
public:
	void spawnApple();
	void generateRandomPosition();
	void printScore();
	void printBestScore();
};


