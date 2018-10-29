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


void Paddle::handleEvents (SDL_Event &e) {
	if (e.type == SDL_KEYDOWN) {
		switch (e.key.keysym.sym) {
		case SDLK_LEFT:
			// add left speed 
			break;
		case SDLK_RIGHT:
			// add right speed
			break;
		default:
			break;
		}
	}
}
