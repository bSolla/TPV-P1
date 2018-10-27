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

void Wall::setScale (int newHeight, int newWidth, WallType type) { 
	width = newWidth;
	height = newHeight;

	setPosition (type);
}


void Wall::setPosition (WallType type) {
	switch (type) {
	case topW:
		position.setX (WINDOW_ORIGIN);
		position.setY (WINDOW_ORIGIN);
		break;
	case rightW:
		position.setX (game->getMapWidth() - width);
		position.setY (WINDOW_ORIGIN);
		break;
	case leftW:
		position.setX (WINDOW_ORIGIN);
		position.setY (WINDOW_ORIGIN);
		break;
	default:
		break;
	}
}
