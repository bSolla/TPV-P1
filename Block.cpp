#include "Block.h"
#include "Game.h"


Block::Block (Game *gamePtr) {
	game = gamePtr;
	blockTexture = game->getTexture (TextureNames::bricks);
}


Block::~Block () {
	game = nullptr;
	blockTexture = nullptr;
}


void Block::setColor (BlockColor newColor) {
	color = newColor;
	row = color / TEXTURE_ATTRIBUTES[TextureNames::bricks].cols; //spriteSheetRow = colorIndex / 3
	col = color - (TEXTURE_ATTRIBUTES[TextureNames::bricks].cols * row); //spriteSeetCol = colorIndex - 3 * spriteSheetRow
}


void Block::render () const {
	SDL_Rect destRect { position.getX (), position.getY (), width, height };

	blockTexture->renderFrame (destRect, row, col);
}