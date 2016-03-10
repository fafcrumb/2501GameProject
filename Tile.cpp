#include "Tile.hpp"

Tile::Tile(int code) {
	if (code == 0) {
		blockability = 1;
	}
	else {
		blockability = 0;
	}
	activeMapCode = code;
	baseMapCode = code;
}

Tile::~Tile(){}

int Tile::returnBlockable() { return blockability; }
int Tile::returnMapCode() { return activeMapCode; }
void Tile::setBlockade() {
	blockability = 1;
	activeMapCode = 2;
}
