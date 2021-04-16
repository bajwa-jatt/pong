#include "PongGame.h"
using namespace utility;

PongGame::PongGame()
	: map(Coordinate(0, 0), Coordinate(79, 24)),
	paddle1(Coordinate(5, 10)),
	paddle2(Coordinate(75, 10)),
	writer(),
	reader()
{
}

void PongGame::start()
{
	Coordinate paddle1Postion = paddle1.getPosition();
	Coordinate paddle2Postion = paddle2.getPosition();
	writer.fillRegion('|', paddle1Postion.X, paddle1Postion.Y, paddle1Postion.X, paddle1Postion.Y + paddle1.getPaddleLength());
	writer.fillRegion('|', paddle2Postion.X, paddle2Postion.Y, paddle2Postion.X, paddle2Postion.Y + paddle2.getPaddleLength());

	writer.setWindowSize(map.getSize());
	writer.drawRectangle(map.getLeft(), map.getTop(), map.getRight(), map.getBottom());
	writer.setCursorVisible(false);
	while (!reader.isEscapePressed())
	{
		update();
	}
}

void PongGame::update()
{
	for (int i = 0; i < 7; i++)
	{
		updateInput();
		Sleep(20); // Sleep for 20 milliseconds
	}

	updateInput();
	updateBallMovement();
	Sleep(20); // Sleep for 20 milliseconds
}

void PongGame::updateInput()
{
	if (reader.isKeyPressed('S')) {
		Coordinate paddle1Postion = paddle1.getPosition();
		if (paddle1Postion.Y+1+paddle1.getPaddleLength() < map.getBottom()) {
			writer.clearRegion(paddle1Postion.X, paddle1Postion.Y, paddle1Postion.X, paddle1Postion.Y + paddle1.getPaddleLength());
		
			paddle1.changeDirection(Direction::Down);
			paddle1.move();

			Coordinate paddle1NewPostion = paddle1.getPosition();
			writer.fillRegion('|', paddle1NewPostion.X, paddle1NewPostion.Y, paddle1NewPostion.X, paddle1NewPostion.Y + paddle1.getPaddleLength());

		}
	}
	if (reader.isKeyPressed('W')) {
		Coordinate paddle1Postion = paddle1.getPosition();
		if (paddle1Postion.Y - 1 > map.getTop()) {
			writer.clearRegion(paddle1Postion.X, paddle1Postion.Y, paddle1Postion.X, paddle1Postion.Y + paddle1.getPaddleLength());

			paddle1.changeDirection(Direction::Up);
			paddle1.move();
			Coordinate paddle1NewPostion = paddle1.getPosition();
			writer.fillRegion('|', paddle1NewPostion.X, paddle1NewPostion.Y, paddle1NewPostion.X, paddle1NewPostion.Y + paddle1.getPaddleLength());
		}
	}

	if (reader.isUpArrowPressed()) {
		Coordinate paddleOldPostion = paddle2.getPosition();
		if (paddleOldPostion.Y - 1 > map.getTop()) {
			writer.clearRegion(paddleOldPostion.X, paddleOldPostion.Y, paddleOldPostion.X, paddleOldPostion.Y + paddle2.getPaddleLength());

			paddle2.changeDirection(Direction::Up);
			paddle2.move();
			Coordinate paddleNewPostion = paddle2.getPosition();
			writer.fillRegion('|', paddleNewPostion.X, paddleNewPostion.Y, paddleNewPostion.X, paddleNewPostion.Y + paddle2.getPaddleLength());
		}
	}

	if (reader.isDownArrowPressed()) {
		Coordinate paddleOldPostion = paddle2.getPosition();
		if (paddleOldPostion.Y + 1 + paddle2.getPaddleLength() < map.getBottom()) {
			writer.clearRegion(paddleOldPostion.X, paddleOldPostion.Y, paddleOldPostion.X, paddleOldPostion.Y + paddle2.getPaddleLength());

			paddle2.changeDirection(Direction::Down);
			paddle2.move();
			Coordinate paddleNewPostion = paddle2.getPosition();
			writer.fillRegion('|', paddleNewPostion.X, paddleNewPostion.Y, paddleNewPostion.X, paddleNewPostion.Y + paddle2.getPaddleLength());
		}
	}
}

void PongGame::updateBallMovement()
{
}
