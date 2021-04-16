#pragma once
#include"Direction.h"
#include"PongBall.h"
#include"Map.h"
#include"ConsoleReader.h"
#include"ConsoleWriter.h"
#include"Paddle.h"
#include"Player.h"
class Game
{
private:
	Player player1;
	Player player2;
	Paddle paddle1;
	Paddle paddle2;
	Map map;
	PongBall pongBall;
	utility::ConsoleReader reader;
	utility::ConsoleWriter writer;
	int x1, y1;

public:
	void start();
	Game();
private:
	void init();
	void Win();
	void scoreUpdate();
	void update();
	void updateInput();
	void updatePaddleInput();
	void updateBallMovement();
};


