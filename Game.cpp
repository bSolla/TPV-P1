#include "Game.h"



Game::Game () {
	if (iniSDL ()) {
		if (iniTextures ()) {
			// walls --we only have 4 so writing them one by one is as long as making two 'for'
			walls[0] = new Wall (this, textures[TextureNames::sideWall]);
			walls[1] = new Wall (this, textures[TextureNames::sideWall]);
			walls[2] = new Wall (this, textures[TextureNames::topWall]);
			walls[3] = new Wall (this, textures[TextureNames::topWall]);
			/*dog = new Dog (renderer, textures[1]);
			helicopter = new Helicopter (renderer, textures[2]);*/

			//read file-> set the new window size and set wall positions

		}
	}
}


Game::~Game () {
	/*delete dog;
	delete helicopter;*/
	for (uint i = 0; i < NUM_TEXTURES; ++i) {
		delete textures[i];
	}

	for (uint i = 0; i < NUM_WALLS; ++i) {
		delete walls[i];
	}
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


void Game::renderBackground () const{
	for (uint i = 0; i < NUM_WALLS; ++i) {
		walls[i]->render ();
	}
}


void Game::handleEvents () {
	SDL_Event event;  

	if (SDL_PollEvent (&event) && !end) {
		if (event.type == SDL_QUIT) {
			end == true;
		}
	}
}


void Game::render () const {

}


void Game::update () {


	handleEvents ();
}


void Game::run () {
	renderBackground ();

	while (!end) {
		render ();
		update ();

		SDL_Delay (DELAY);
	}
}

