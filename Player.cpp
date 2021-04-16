#include "Player.h"


Player::Player() {
	this->playerName = " ";
	this->Score = 0;
}

std::string Player::getPlayerName() {
	return playerName;
}

char Player::getScore() {
	std::string s1 = std::to_string(this->Score);
	char s2 = s1.at(0);
	return s2;
}

int Player::getScore1() {
	return this->Score;
}

void Player::setScore(int score) {
	this->Score += score;
}

void Player::setName(std::string name) {
	this->playerName = name;
}
