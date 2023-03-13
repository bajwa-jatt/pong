#include "PongBall.h"

PongBall::PongBall() :PongBall(Direction::Right,Direction::Down, {0,0}) {

}

PongBall::PongBall(Direction ballDirection1, Direction ballDirection2, Position ballPosition ) {
	this->ballDirection1 = ballDirection1;
	this->ballDirection2 = ballDirection2;
	this->ballPosition = ballPosition;
	this->initBallPosition = ballPosition;
}

Direction PongBall::getBallDirection1() {
	return ballDirection1;
}

Direction PongBall::getBallDirection2() {
	return ballDirection2;
}

Position PongBall::getInitialPosition() {
	return initBallPosition;
}

Position PongBall::getBallPosition() {
	return ballPosition;
}

void PongBall::setBallDirection1(Direction direction) {
	this->ballDirection1 = direction;
}

void PongBall::setBallDirection2(Direction direction) {
	this->ballDirection2 = direction;
}

void PongBall::setBallPosition(Position position) {
	this->ballPosition = position;
}
