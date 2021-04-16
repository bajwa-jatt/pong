#pragma once
#include"Direction.h"
#include"Position.h"
using utility::Position;
class PongBall
{
private:
	Direction ballDirection1,ballDirection2;
	Position ballPosition,initBallPosition;
public:
	PongBall();
	PongBall(Direction ballDirection, Direction ballDirection2, Position ballPosition);
	Position getInitialPosition();
	Direction getBallDirection1();
	Direction getBallDirection2();
	Position getBallPosition();

	void setBallDirection1(Direction direction);
	void setBallDirection2(Direction direction);
	void setBallPosition(Position position);

};

