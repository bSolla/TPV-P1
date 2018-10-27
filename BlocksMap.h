#pragma once
#include <fstream>
#include "Block.h"


const string LEVELS_PATH = "levels\\";

class Game;

class BlocksMap {
// --------------------- variables------------------------------------------------------
private:
	uint rows, cols;
	uint cellHeight = 20, cellWidth = 60;
	uint mapHeight, mapWidth;
	uint nBlocks;
	Block*** cells = nullptr;
	Game* game = nullptr;

// ---------------------- methods ------------------------------------------------------
public:
	BlocksMap (Game* gamePtr);
	~BlocksMap ();

	void load (const string &filename);
	Block* collides (const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector);
	Block* blockAt (const Vector2D& p);
	void render () const;
};

