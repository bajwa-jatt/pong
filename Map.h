#pragma once
#include"Coordinate.h"
using utility::Coordinate;

class Map
{
private:
	Coordinate topLeft, bottomRight, topRight, bottomLeft,size;
public:
	Map();
	Map(Coordinate topLeft, Coordinate bottomRight);
	Coordinate getTopLeft();
	Coordinate getBottomLeft();
	Coordinate getTopRight();
	Coordinate getBottomRight();
	Coordinate getSize();

   int getLeft();
   int getRight();
   int getTop();
   int getBottom();
};

