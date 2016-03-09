#include "Tile.hpp"
// See hpp file for description
Tile::Tile(int code) {
	if (code > 4) {
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
