#pragma once
#include <iostream>
#include <new>
#include <string>
#include "checkML.h"
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


const string LEVEL_SHARED_NAME = "level0";
const string LEVEL_EXTENSION = ".ark";

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
	bool levelClear = false;
	uint currentLevel = 1;

	uint cellHeight = 20, cellWidth = 60;
	uint mapHeight, mapWidth;

// ---------------------- methods ------------------------------------------------------
public:
	Game ();
	~Game ();

	// takes in the map dimensions calculated in BlocksMap::load() and scales the walls and window to fit accordingly
	void scaleObjects (uint newMapWidth, uint newMapHeight);
	// main game loop, runs until a quit event is detected
	void run ();

	// getter functions
	uint getMapWidth () const { return mapWidth; }
	Texture* getTexture (TextureNames textureName) const { return textures[textureName]; }
	SDL_Renderer* getRenderer () const { return renderer; }

	// setter functions
	void setLevelClear () { levelClear = true; }

private:
	// initializes SDL and returns true if everything goes smoothly-- false is used to abort
	bool iniSDL ();
	// initializes all textures and returns true if everything went smoothly-- false used to abort
	bool iniTextures ();
	// gives the ball and paddle their initial positions, calculated from the map dimensions
	void positionObjects ();

	// renders the walls
	void renderBackground () const;
	// polls events, and checks for quit events. also calls Paddle::handleEvents(SDL_Event &e), which handles keyboard events
	void handleEvents ();
	// if the control bool levelClear is true, deletes the old BlocksMap, creates a new one and reads all the corresponding info
	void handleLevelUp ();
	// calls the respective render methods from ball, paddle and map and then draws 
	void render () const;
	// calls the update methods from ball and paddle
	void update ();
	
	// destroys both renderer and window and quits SDL
	void quitSDL ();
};

