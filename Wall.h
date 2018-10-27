#pragma once
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
	
	void setScale (int newHeight, int newWidth, WallType type);
	void setPosition (WallType type);

	void render () const;
};

