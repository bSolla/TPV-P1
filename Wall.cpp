#include "Wall.h"
#include "Game.h"


Wall::Wall (Game* gamePtr, Texture* texturePtr) {
	game = gamePtr;
	wallTexture = texturePtr;
	SDL_QueryTexture (wallTexture->getTexture(), NULL, NULL, &width, &height);
}


Wall::~Wall () {
	game = nullptr;
	wallTexture = nullptr;
}


void Wall::render () const {
	SDL_Rect destRect { position.getX (), position.getY (), width, height };

	wallTexture->render (destRect);
}
