#pragma once
#include "Texture.h"
#include "Vector2D.h"

class Game;

class Paddle {
// --------------------- variables------------------------------------------------------
private:
	int height = 20, width = 60;
	Vector2D position, moveDirection;

	Texture* texture = nullptr;
	Game* game = nullptr;

// ---------------------- methods ------------------------------------------------------
public:
	Paddle (Game* gamePtr);
	~Paddle ();

	void render() const;
	void setInitialPosition (int mapWidth, int verticalOffset);
};

