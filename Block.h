#pragma once
#include "Vector2D.h"
#include "Texture.h"

class Game; // just in case we need game info later into development

enum BlockColor { blue, green, red, yellow, black, purple};

class Block {
// --------------------- variables------------------------------------------------------
private:
	Vector2D position; // position in the map
	int width, height;
	int row, col; // position in the sprite sheet
	BlockColor color;

	Texture* blockTexture = nullptr;
	Game* game = nullptr;

// ---------------------- methods ------------------------------------------------------
public:
	Block () {};
	Block (Game *gamePtr);
	~Block ();

	void setColor (BlockColor newColor);
	void setScale (int newWidth, int newHeight) { width = newWidth; height = newHeight; }
	void render () const;
};

