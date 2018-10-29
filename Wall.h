#pragma once
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"


class Game; 

enum WallType { topW, rightW, leftW};
const double WINDOW_ORIGIN = 0.0;

class Wall {
// --------------------- variables------------------------------------------------------
private:
	Vector2D position;
	int width, height, mapWidth;
	Texture* wallTexture = nullptr;
	Game* game = nullptr;

// ---------------------- methods ------------------------------------------------------
public:
	Wall (Game* gamePtr, Texture* texturePtr);
	~Wall ();

	// sets the correct proportions so the rendered wall can fit the screen
	void setScale (int newHeight, int newWidth, WallType type);
	// sets the wall's position depending on the type (top, left or right)
	void setPosition (WallType type);

	// renders the wall
	void render () const;
};

