#pragma once
#include <fstream>
#include "Block.h"


const string LEVELS_PATH = "..\\levels\\";

class Game;

class BlocksMap {
// --------------------- variables------------------------------------------------------
private:
	uint rows, cols;
	uint cellHeight, cellWidth;
	uint mapHeight, mapWidth;
	uint nBlocks;
	Block*** cells = nullptr;
	Game* game = nullptr;

// ---------------------- methods ------------------------------------------------------
public:
	BlocksMap (Game* gamePtr);
	~BlocksMap ();

	void load (const string &filename);
	void render () const;
};

