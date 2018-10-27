#include "Paddle.h"
#include "Game.h"



Paddle::Paddle (Game* gamePtr) {
	game = gamePtr;
	texture = game->getTexture (TextureNames::paddle_);
}


Paddle::~Paddle () {
	game = nullptr;
	texture = nullptr;
}


void Paddle::render() const {
	SDL_Rect destRect{ position.getX(), position.getY(), width, height };
	texture->render(destRect);
}


void Paddle::setInitialPosition (int mapWidth, int verticalOffset) {
	position.setX (double (mapWidth) / 2);
	position.setY (double (verticalOffset));
}