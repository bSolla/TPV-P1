#include "Game.h"



Game::Game () {
	if (iniSDL ()) {
		if (iniTextures ()) {
			walls[WallType::leftW] = new Wall (this, textures[TextureNames::sideWall]);
			walls[WallType::rightW] = new Wall (this, textures[TextureNames::sideWall]);
			walls[WallType::topW] = new Wall (this, textures[TextureNames::topWall]);
			
			ball = new Ball(this);
			paddle = new Paddle(this);
			map = new BlocksMap(this);

			map->load(LEVEL_SHARED_NAME + to_string(currentLevel) + LEVEL_EXTENSION);

			positionObjects ();
		}
	}
}


Game::~Game () {
	delete ball;
	delete paddle;
	delete map;

	for (uint i = 0; i < NUM_TEXTURES; ++i) {
		delete textures[i];
	}

	for (uint i = 0; i < NUM_WALLS; ++i) {
		delete walls[i];
	}

	quitSDL ();
}


bool Game::iniSDL () {
	bool everythingOk = true;

	SDL_Init(SDL_INIT_EVERYTHING); 
	window = SDL_CreateWindow("test", WIN_X, WIN_Y, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE); 
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); 
	
	if (window == nullptr || renderer == nullptr) {
		cout << "Error initializing SDL\n";
		everythingOk = false;
	}

	return everythingOk;
}


bool Game::iniTextures () {
	string errorMsg;

	for (uint i = 0; i < NUM_TEXTURES; ++i) {
		textures[i] = new Texture (renderer, IMAGES_PATH + TEXTURE_ATTRIBUTES[i].filename, TEXTURE_ATTRIBUTES[i].rows, TEXTURE_ATTRIBUTES[i].cols);
	}

	errorMsg = SDL_GetError ();
	cout << errorMsg;

	return errorMsg == ""; // true if sdl_getError didn't catch any errors
}


void Game::scaleObjects (uint newMapWidth, uint newMapHeight) {
	mapHeight = newMapHeight;
	mapWidth = newMapWidth;

	walls[WallType::leftW]->setScale (mapHeight, cellHeight, WallType::leftW);
	walls[WallType::rightW]->setScale (mapHeight, cellHeight, WallType::rightW);
	walls[WallType::topW]->setScale (cellHeight, mapWidth, WallType::topW);

	SDL_SetWindowSize (window, mapWidth, mapHeight);
}


void Game::positionObjects () {
	paddle->setInitialPosition (mapWidth, mapHeight - cellHeight * 2);
	ball->setInitialPosition (mapWidth, mapHeight - cellHeight * 3);
}


void Game::renderBackground () const{
	for (uint i = 0; i < NUM_WALLS; ++i) {
		walls[i]->render ();
	}
}


void Game::handleEvents () {
	SDL_Event event;  

	if (SDL_PollEvent (&event)) {
		if (event.type == SDL_QUIT) {
			end = true;
		}
		else {
			paddle->handleEvents (event);
		}
	}
}


void Game::handleLevelUp () {
	if (levelClear) {
		delete map;	// delete the old map and make a new one for the new level
		map = new BlocksMap (this);

		map->load (LEVEL_SHARED_NAME + to_string (currentLevel) + LEVEL_EXTENSION);
		positionObjects ();

		levelClear = false;
	}
}


bool Game::collides (SDL_Rect ballRect, Vector2D ballSpeed, Vector2D &collVector) {
	bool ballCollides = false;

	// if collides with any of the walls...
	if (walls[WallType::leftW]->collides (ballRect, collVector) ||
		walls[WallType::rightW]->collides(ballRect, collVector) ||
		walls[WallType::topW]->collides(ballRect, collVector)) {
		
		ballCollides = true;
	 }

	// if collides with the blocks...
	else if (map->collides (ballRect, ballSpeed, collVector) != nullptr) {
		ballCollides = true;
	}
	
	// if collides with the paddle...
	else if (paddle->collides (ballRect, collVector)) {
		ballCollides = true;
	}

	return ballCollides;
}


void Game::render () const {
	SDL_RenderClear (renderer);

	renderBackground ();
	map->render ();
	paddle->render ();
	ball->render ();
	
	SDL_RenderPresent (renderer);
}


void Game::update () {
	ball->update();
	paddle->update();

	handleEvents ();
	handleLevelUp ();
}


void Game::run () {
	while (!end) {
		render ();
		update ();

		SDL_Delay (DELAY);
	}
}


void Game::quitSDL () {
	SDL_DestroyRenderer (renderer);
	SDL_DestroyWindow (window);
	SDL_Quit ();
}
