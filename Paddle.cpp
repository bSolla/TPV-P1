#include "Paddle.h"
#include "Game.h"



Paddle::Paddle (Game* gamePtr) {
	game = gamePtr;
	texture = game->getTexture (TextureNames::paddle_);
	speed.setY (0.0);
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
			speed.setX (-basicIncrement);
			break;
		case SDLK_RIGHT:
			speed.setX (basicIncrement);
			break;
		default:
			break;
		}
	}
	else if (e.type == SDL_KEYUP) {
		speed.setX (0.0);
	}
}


void Paddle::update () {
	mapWidth = game->getMapWidth ();

	if (position.getX () > 20 && speed.getX() < 0) {
		position = position + speed;
	}
	if (position.getX () < (mapWidth - width - 20) && speed.getX() > 0)
		position = position + speed;
	
}
