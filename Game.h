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

// added the underscores after ball and paddle to avoid mixing them with the variables ball and paddle
enum TextureNames { ball_, bricks, paddle_, sideWall, topWall };

// ---------------------- constants -----------------------------------------------------
const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint WIN_X = SDL_WINDOWPOS_CENTERED;
const uint WIN_Y = SDL_WINDOWPOS_CENTERED;

const uint NUM_TEXTURES = 5;
const uint NUM_WALLS = 3;

const uint DELAY = 60;

const string IMAGES_PATH = "images\\";
const TextureAttributes TEXTURE_ATTRIBUTES[NUM_TEXTURES] = 
	{	{ "ball.png", 1, 1 },
		{ "bricks.png", 3, 2 },
		{ "paddle.png", 1, 1 },
		{ "side.png", 1, 1 },
		{ "topSide.png", 1, 1 }
	};


const string LEVEL_NAME = "level01.ark";


class Game {
// --------------------- variables------------------------------------------------------
private: 
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	Wall* walls[NUM_WALLS];
	Texture* textures[NUM_TEXTURES]; 
	BlocksMap* map = nullptr;
	Ball* ball = nullptr;
	Paddle* paddle = nullptr;

	bool end = false;
	uint cellHeight = 20, cellWidth = 60;
	uint mapHeight, mapWidth;

// ---------------------- methods ------------------------------------------------------
public:
	Game ();
	~Game ();
	
	uint getMapWidth () const { return mapWidth; }
	Texture* getTexture (TextureNames textureName) const { return textures[textureName]; }
	SDL_Renderer* getRenderer () const { return renderer; }

	void scaleObjects (uint newMapWidth, uint newMapHeight);
	void run ();

private:
	bool iniSDL ();
	bool iniTextures ();
	void positionObjects ();

	void handleEvents ();
	void renderBackground () const;
	void render () const;
	void update ();
	
	void quitSDL ();
};

