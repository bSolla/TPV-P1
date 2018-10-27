#pragma once
#include "Vector2D.h"
#include "Texture.h"

class Game;

enum BlockColor { blue, green, red, yellow, black, purple};

const uint WALL_THICKNESS = 20;

class Block {
// --------------------- variables------------------------------------------------------
private:
	Vector2D position; // position in the map
	int width = 60, height = 20;
	int row, col; // position in the sprite sheet
	BlockColor color;

	Texture* blockTexture = nullptr;
	Game* game = nullptr;

// ---------------------- methods ------------------------------------------------------
public:
	Block () {};
	Block (Game *gamePtr, int colorIndex);
	~Block ();

	void setColor (BlockColor newColor);
	void render () const;

	int getX () const { return position.getX (); }
	int getY () const { return position.getY (); }

	void setPosition (uint matrixColumnIndex, uint matrixRowIndex);
};

