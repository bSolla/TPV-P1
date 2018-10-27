#include "BlocksMap.h"
#include "Game.h"


BlocksMap::BlocksMap (Game* gamePtr) {
	game = gamePtr;
}


BlocksMap::~BlocksMap () {
	if (cells != nullptr) {
		for (int c = 0; c < cols; ++c) {
			for (int r = 0; r < rows; ++r) {
				delete cells[r][c];
			}
		}
	}
}


void BlocksMap::load (const string & filename) {
	ifstream file;
	int color = 0;

	file.open (LEVELS_PATH + filename);
	if (!file.is_open ()) {
		throw ("couldn't open " + filename);
	}
	else {
		file >> rows >> cols;
									
		mapWidth = cellWidth * cols + cellHeight * 2; // to account for the walls we add cellHeight * 2
		mapHeight = 2 * (cellHeight * rows) + cellHeight * 2;

		game->scaleObjects (mapWidth, mapHeight);

		// pointer initialization
		cells = new Block**[rows];

		for (uint r = 0; r < rows; ++r) {
			cells[r] = new Block*[cols];
		}

		// fill values in
		for (uint r = 0; r < cols; ++r) {
			for (uint c = 0; c < rows; ++c) {
				file >> color;

				if (color == 0) { 
					cells[c][r] = nullptr;
				}
				else {
					cells[c][r] = new Block (game, BlockColor(color));
					cells[c][r]->setPosition (c, r);
				}
			}
		}

		file.close ();
	}
}


/* Dados el rectángulo y vector de dirección de la pelota, devuelve un puntero al 
   bloque con el que ésta colisiona (nullptr si no colisiona con nadie) y el 
   vector normal perpendicular a la superficie de colisión.
*/
Block* BlocksMap::collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector){
	Vector2D topLeftPoint = { double (ballRect.x), double (ballRect.y) }; 
	Vector2D topRightPoint = { double (ballRect.x + ballRect.w), double (ballRect.y) }; 
	Vector2D bottomLeftPoint = { double (ballRect.x), double (ballRect.y + ballRect.h) }; 
	Vector2D bottomRightPoint = { double (ballRect.x + ballRect.w), double (ballRect.y + ballRect.h) }; // bottom-right
	Block* block = nullptr;

	if (ballVel.getX() < 0 && ballVel.getY() < 0){
		if ((block = blockAt(topLeftPoint))){
			if ((block->getY() + cellHeight - topLeftPoint.getY()) <= (block->getX() + cellWidth - topLeftPoint.getX()))
				collVector = {0,1}; // Borde inferior mas cerca de topLeftPoint
			else
				collVector = {1,0}; // Borde dcho mas cerca de topLeftPoint
		} else if ((block = blockAt(topRightPoint))) { collVector = {0,1};
		} else if ((block = blockAt(bottomLeftPoint))) collVector = {1,0};
	} else if (ballVel.getX() >= 0 && ballVel.getY() < 0){
		if ((block = blockAt(topRightPoint))){
			if (((block->getY() + cellHeight - topRightPoint.getY()) <= (topRightPoint.getX() - block->getX())) || ballVel.getX() == 0)
				collVector = {0,1}; // Borde inferior mas cerca de topRightPoint
			else
				collVector = {-1,0}; // Borde izqdo mas cerca de topRightPoint
		} else if ((block = blockAt(topLeftPoint))) { collVector = {0,1};
		} else if ((block = blockAt(bottomRightPoint))) collVector = {-1,0};
	} else if (ballVel.getX() > 0 && ballVel.getY() > 0){
		if ((block = blockAt(bottomRightPoint))){
			if (((bottomRightPoint.getY() - block->getY()) <= (bottomRightPoint.getX() - block->getX()))) // || ballVel.getX() == 0)
				collVector = {0,-1}; // Borde superior mas cerca de bottomRightPoint
			else
				collVector = {-1,0}; // Borde dcho mas cerca de bottomRightPoint
		} else if ((block = blockAt(bottomLeftPoint))) { collVector = {0,-1};
		} else if ((block = blockAt(topRightPoint))) collVector = {-1,0};
	} else if (ballVel.getX() < 0 && ballVel.getY() > 0){
		if ((block = blockAt(bottomLeftPoint))){
			if (((bottomLeftPoint.getY() - block->getY()) <= (block->getX() + cellWidth - bottomLeftPoint.getX()))) // || ballVel.getX() == 0)
				collVector = {0,-1}; // Borde superior mas cerca de bottomLeftPoint
			else
				collVector = {1,0}; // Borde dcho mas cerca de topLeftPoint
		} else if ((block = blockAt(bottomRightPoint))) { collVector = {0,-1};
		} else if ((block = blockAt(topLeftPoint))) collVector = {1,0};
	}
	return block;
}


/*  Devuelve el puntero al bloque del mapa de bloques al que pertenece el punto p.
	En caso de no haber bloque en ese punto (incluido el caso de que p esté fuera
	del espacio del mapa) devuelve nullptr. 	
*/
Block* BlocksMap::blockAt(const Vector2D& p){
	return nullptr;
}


void BlocksMap::render () const {
	for (int c = 0; c < cols; ++c) {
		for (int r = 0; r < rows; ++r) {
			if (cells[c][r] != nullptr)
				cells[c][r]->render ();
		}
	}
}
