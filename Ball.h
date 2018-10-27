#pragma once
#include "Texture.h"
#include "Vector2D.h"

class Game;

class Ball {
// --------------------- variables------------------------------------------------------
private:
	int cellSize = 20;
	Vector2D position, movDirection;

	Texture* texture = nullptr;
	Game* game = nullptr;

// ---------------------- methods ------------------------------------------------------
public:
	Ball (Game* gamePtr);
	~Ball ();

	void render () const;

	void setInitialPosition (int mapWidth, int verticalOffset);
};

