#include "Paddle.h"

Paddle::Paddle(Coordinate position)
	:position(position), direction(Direction::Down)
{
	this->position = position;
}

void Paddle::move() {
	if (direction == Direction::Up) {
		position.Y -= 1;

	}
	else if (direction == Direction::Down) {
		position.Y += 1;
	}
}

void Paddle::setPosition(Coordinate position) {
	this->position = position;
}

utility::Coordinate Paddle::getPosition()
{
	return utility::Coordinate(position.X, position.Y);
}

Direction Paddle::getDirection()
{
	return Direction(direction);
}

int Paddle::getPaddleLength()
{
	return length;
}

void Paddle::changeDirection(Direction direction) {
	this->direction = direction;
}