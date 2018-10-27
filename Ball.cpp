#include "Ball.h"
#include "Game.h"


Ball::Ball (Game* gamePtr) {
	game = gamePtr;
	texture = game->getTexture (TextureNames::ball_);
}


Ball::~Ball () {
	game = nullptr;
	texture = nullptr;
}


void Ball::setInitialPosition (int mapWidth, int verticalOffset) {
	position.setX (double (mapWidth) / 2 + double (cellSize));
	position.setY (double (verticalOffset));
}


void Ball::render () const {
	SDL_Rect destRect { position.getX (), position.getY (), cellSize, cellSize };

	texture->render (destRect);
}
