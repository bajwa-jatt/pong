#include "Game.h"

Game::Game() :reader(),writer(),player1(),player2(),
paddle1(Coordinate(5, 10)),
paddle2(Coordinate(75, 10)),
map(Coordinate(0, 1), Coordinate(79, 24)) ,
pongBall(Direction::Left,Direction::Down, {34,12})
{
	this->x1 = -1;
	this->y1 = 0;
}

void Game::scoreUpdate() {
	
		writer.setCharacterAtPosition({ 17,0 }, player1.getScore());
		writer.setCharacterAtPosition({ 49,0 }, player2.getScore());
}

void Game::init() {
	std::cout << "Player1's Score :" << player1.getScore();
	std::cout << "\t\tPlayer2's Score :" << player2.getScore();
	writer.fillRegion('|', paddle1.getPosition().X, paddle1.getPosition().Y, paddle1.getPosition().X, paddle1.getPosition().Y + paddle1.getPaddleLength());
	writer.fillRegion('|', paddle2.getPosition().X, paddle2.getPosition().Y, paddle2.getPosition().X, paddle2.getPosition().Y + paddle2.getPaddleLength());
	writer.setWindowSize(map.getSize().X, map.getSize().Y + 1);
	writer.setCursorVisible(false);
	writer.drawRectangle(map.getTopLeft(), map.getBottomRight());
}

void Game::start() {
	init();
	int flag = 0;
	while (!reader.isEscapePressed()) {
		if ((player1.getScore1()||player2.getScore1())!=10) {
			update();
		}
		else if(flag==0){
			Win();
			flag = 1;
		}
	};

}

void Game::update() {
	updateInput();
	updateBallMovement();
	updatePaddleInput();
	Sleep(50);
	updateBallMovement();
}

void Game::Win() {
	if( player1.getScore1() < 9) {
		writer.writeLine("\n\nPlayer 1 Wins");
	}
	else {
		writer.writeLine("\n\nplayer 2 Wins");
	}
}


void Game::updatePaddleInput() {
	if (reader.isKeyPressed('S')) {
		Coordinate paddle1Postion = paddle1.getPosition();
		if (paddle1Postion.Y + 1 + paddle1.getPaddleLength() < map.getBottom()) {
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

void Game::updateInput() {
	Coordinate ball = pongBall.getBallPosition();
	switch (pongBall.getBallDirection1())
	{
	case Direction::Right:
		this->x1 = 1;
		ball.X++;
		switch (pongBall.getBallDirection2()) {

		case Direction::Down:
			ball.Y++;
			this->y1 = 1;
			if (map.getBottom() - 2 == pongBall.getBallPosition().Y) {
				pongBall.setBallDirection2(Direction::Up);
			}
			break;

		case Direction::Up:
			ball.Y--;
			this->y1 = -1;
			if (map.getTop() + 2 == pongBall.getBallPosition().Y) {
				pongBall.setBallDirection2(Direction::Down);
			}
			break;
		}

		pongBall.setBallPosition({(DOUBLE)ball.X,(DOUBLE)ball.Y });
		if (paddle2.getPosition().X - 2 == pongBall.getBallPosition().X && pongBall.getBallPosition().Y >= paddle2.getPosition().Y && pongBall.getBallPosition().Y <= paddle2.getPosition().Y + paddle2.getPaddleLength()) {
			pongBall.setBallDirection1(Direction::Left);
		}
		if (map.getRight() == pongBall.getBallPosition().X) {
			Coordinate init = pongBall.getInitialPosition();
			player1.setScore(1);
			scoreUpdate();
			writer.setCharacterAtPosition((INT)pongBall.getBallPosition().X - x1, (INT)pongBall.getBallPosition().Y - y1, ' ');
			pongBall.setBallPosition({ (DOUBLE)init.X,(DOUBLE)init.Y });
			Sleep(1000);
		}
		break;


	case Direction::Left:
		this->x1 = -1;
		ball.X--;
		switch (pongBall.getBallDirection2()) {

		case Direction::Down:
			ball.Y++;
			this->y1 = 1;
			if (map.getBottomRight().Y - 2 == pongBall.getBallPosition().Y) {
				pongBall.setBallDirection2(Direction::Up);
			}
			break;

		case Direction::Up:
			ball.Y--;
			this->y1 = -1;
			if (map.getTopLeft().Y + 2 == pongBall.getBallPosition().Y) {
				pongBall.setBallDirection2(Direction::Down);
			}
			break;
		}
		pongBall.setBallPosition({ (DOUBLE)ball.X,(DOUBLE)ball.Y });
		if(paddle1.getPosition().X + 2 == pongBall.getBallPosition().X && pongBall.getBallPosition().Y >= paddle1.getPosition().Y && pongBall.getBallPosition().Y <= paddle1.getPosition().Y + paddle1.getPaddleLength()) {
			pongBall.setBallDirection1(Direction::Right);
		}
		if (map.getLeft() == pongBall.getBallPosition().X) {
			Coordinate init=pongBall.getInitialPosition();
			writer.setCharacterAtPosition((INT)pongBall.getBallPosition().X - x1, (INT)pongBall.getBallPosition().Y - y1, ' ');
			player2.setScore(1);
			scoreUpdate();
			pongBall.setBallPosition({ (DOUBLE)init.X,(DOUBLE)init.Y });
			Sleep(1000);
		}
		break;
	}
}

void Game::updateBallMovement() {
	
	writer.setCharacterAtPosition((INT)pongBall.getBallPosition().X,(INT)pongBall.getBallPosition().Y,'*');
	writer.setCharacterAtPosition((INT)pongBall.getBallPosition().X - x1, (INT)pongBall.getBallPosition().Y - y1, ' ');

}