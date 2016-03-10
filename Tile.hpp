#pragma once


class Tile
{
public:
	Tile(int);
	~Tile();
	int returnBlockable();
	int returnMapCode();
	void setBlockade();
private:
	int blockability;
	int activeMapCode;
	int baseMapCode;
};
