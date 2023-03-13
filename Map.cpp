#include "Map.h"

Map::Map() :Map({ 0,0 }, { 0,0 }) {
}

Map::Map(Coordinate topLeft, Coordinate bottomRight)
	: topLeft(topLeft),
	bottomRight(bottomRight),
	topRight(bottomRight.X, topLeft.Y),
	bottomLeft(topLeft.X, bottomRight.Y),
	size(bottomRight.X - topLeft.X + 1, bottomRight.Y - topLeft.Y + 1)

{ }

Coordinate Map::getTopLeft() {
	return this->topLeft;
}

Coordinate Map::getBottomLeft() {
	return this->bottomLeft;
}

Coordinate Map::getTopRight() {
	return this->topRight;
}

Coordinate Map::getBottomRight() {
	return this->bottomRight;
}

Coordinate Map::getSize() {
	return size;
}


int Map::getLeft()
{
	return topLeft.X;
}

int Map::getRight()
{
	return bottomRight.X;
}

int Map::getTop()
{
	return topLeft.Y;
}

int Map::getBottom()
{
	return bottomLeft.Y;
}