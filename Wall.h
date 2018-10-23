#pragma once
#include "Vector2D.h"
#include "Texture.h"


class Game; // just in case we need game info later into development

class Wall {
// --------------------- variables------------------------------------------------------
private:
	Vector2D position;
	int width, height;
	Texture* wallTexture = nullptr;
	Game* game = nullptr;

// ---------------------- methods ------------------------------------------------------
public:
	Wall (Game* gamePtr, Texture* texturePtr);
	~Wall ();

	void setPosition (const Vector2D &newPosition) { position = newPosition; }
	void setScale (int newHeight, int newWidth) { width = newWidth; height = newHeight; }
	void render () const;
};

