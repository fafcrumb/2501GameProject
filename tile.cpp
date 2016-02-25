#include "tile.h"

tile::tile(int x, int y, int pic) {
	xPoint = x;
	yPoint = y;
	picType = pic;
	passable = pic % 3;
}

tile::~tile() {}

int tile::getCollision() {
	return passable;
}

int tile::getPicType() {
	return picType;
}

int tile::getX() {
	return xPoint;
}

int tile::getY() {
	return yPoint;
}
