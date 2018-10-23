#pragma once
#include <iostream>
#include <new>
#include "Texture.h"
#include "Ball.h"
#include "BlocksMap.h"
#include "Paddle.h"
#include "Wall.h"

// ------------------ type definitions ---------------------------------------------------
struct TextureAttributes {
	string filename;
	uint cols;
	uint rows;
};
enum TextureNames { ball, bricks, paddle, sideWall, topWall };

// ---------------------- constants -----------------------------------------------------
const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint WIN_X = SDL_WINDOWPOS_CENTERED;
const uint WIN_Y = SDL_WINDOWPOS_CENTERED;

const uint NUM_TEXTURES = 5;
const uint NUM_WALLS = 4;

const uint DELAY = 60;

const string IMAGES_PATH = "..\\images\\";
const TextureAttributes TEXTURE_ATTRIBUTES[NUM_TEXTURES] = 
	{	{ "ball.png", 1, 1 },
		{ "bricks.png", 3, 2 },
		{ "paddle.png", 1, 1 },
		{ "side.png", 1, 1 },
		{ "topSide.png", 1, 1 }
	};



class Game {
// --------------------- variables------------------------------------------------------
private: 
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	Wall* walls[NUM_WALLS];
	Texture* textures[NUM_TEXTURES]; 

	bool end = false;


// ---------------------- methods ------------------------------------------------------
public:
	Game ();
	~Game ();
	
	void run ();
	Texture* getTexture (TextureNames textureName) const { return textures[textureName]; }
	SDL_Renderer* getRenderer () const { return renderer; }

private:
	bool iniSDL ();
	bool iniTextures ();
	void scaleObjects ();
	void handleEvents ();
	void renderBackground () const;
	void render () const;
	void update ();
};

