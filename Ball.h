#pragma once
#include "checkML.h"
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

	// renders the ball
	void render () const;

	// initializes the ball position in the center of the map, just over the paddle
	void setInitialPosition (int mapWidth, int verticalOffset);
};

