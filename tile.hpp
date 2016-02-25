#pragma once
class tile
{
public:
	tile(int, int, int);
	~tile();
	int getPicType();
	int getCollision();
	int getX();
	int getY();
private:
	int picType;
	int xPoint;
	int yPoint;
	int passable;
};
