#pragma once
#include <fstream>
#include "Block.h"
#include "checkML.h"

const string LEVELS_PATH = "levels\\";

class Game;

class BlocksMap {
// --------------------- variables------------------------------------------------------
private:
	uint rows, cols;
	uint cellHeight = 20, cellWidth = 60;
	uint mapHeight, mapWidth;
	uint nBlocks = 0;

	Block*** cells = nullptr;
	Game* game = nullptr;

// ---------------------- methods ------------------------------------------------------
public:
	BlocksMap (Game* gamePtr);
	~BlocksMap ();

	// loads data from the .ark files and saves it to a Block matrix (cells); also scales the window size according to the number of rows and cols
	void load (const string &filename);
	Block* collides (const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector);
	Block* blockAt (const Vector2D& p);
	// renders the whole Block matrix
	void render () const;
};

