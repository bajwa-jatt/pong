#pragma once
#include"Strings.h"
class Player
{
private:
	std::string playerName;
	int Score;
public:
	Player();
	std::string getPlayerName();
	char getScore();
	int getScore1();
	void setScore(int score);
	void setName(std::string name);
};

