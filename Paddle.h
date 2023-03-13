#pragma once
#include"Coordinate.h"
#include"Direction.h"
using utility::Coordinate;

class Paddle
{
private:
	Coordinate position;
	const int length=5;
	Direction direction;
public:
	Paddle(utility::Coordinate position);

	void move();

	utility::Coordinate getPosition();
	Direction getDirection();

	int getPaddleLength();

	void setPosition(Coordinate position);
	void changeDirection(Direction direction);
};


