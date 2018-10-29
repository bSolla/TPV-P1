#pragma once
#include "checkML.h"
#include "Texture.h"
#include "Vector2D.h"

class Game;

class Paddle {
// --------------------- variables------------------------------------------------------
private:
	int height = 20, width = 60;
	Vector2D position, speed;

	Texture* texture = nullptr;
	Game* game = nullptr;

// ---------------------- methods ------------------------------------------------------
public:
	Paddle (Game* gamePtr);
	~Paddle ();

	// renders the paddle
	void render() const;
	// initializes the paddle position to the middle of the map and a vertical offset
	void setInitialPosition (int mapWidth, int verticalOffset);
	// given a SDL_Event e, checks for left/right arrows and changes the paddle's speed;
	void handleEvents (SDL_Event &e);
};

