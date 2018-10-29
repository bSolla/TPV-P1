
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "Game.h"
#include "checkML.h"
using namespace std;


int main(int argc, char* argv[]){
	_CrtSetDbgFlag (_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Game* game = new Game ();

	game->run ();

	delete game;

	return 0;
}