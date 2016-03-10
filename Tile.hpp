#pragma once

// This class is used to hold the data for the individual tiles on the map neccesary for the interaction between the player vehicle and the land scape
// This class is used by classes that include model with the Tilemap getting the neccesary information from this class through camera
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
