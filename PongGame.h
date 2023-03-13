#pragma once
#include"Map.h"
#include"Paddle.h"
#include "ConsoleWriter.h"
#include "ConsoleReader.h"

class PongGame
{
private:
	Paddle paddle1;
	Paddle paddle2;
	Map map;
	utility::ConsoleWriter writer;
	utility::ConsoleReader reader;
public:
	PongGame();
	void start();

private:
	void update();
	void updateInput();
	void updateBallMovement();
};
