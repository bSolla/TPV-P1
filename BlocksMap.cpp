#include "BlocksMap.h"

//TODO FIX POINTERS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


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
	int color;

	file.open (LEVELS_PATH + filename);
	if (!file.is_open ()) {
		throw ("couldn't open " + filename);
	}
	else {
		file >> rows >> cols;

		// pointer initialization
		for (uint r = 0; r < rows; ++r) {
			cells[r] = new Block[cols];
		}

		// fill values in
		for (uint c = 0; c < cols; ++c) {
			for (uint r = 0; r < rows; ++r) {
				file >> color;

				if (color == 0) { 
					cells[c][r] = nullptr;
				}
				else {
					cells[c][r] = new Block (game);
				}
			}
		}
	}
}


void BlocksMap::render () const {
	for (int c = 0; c < cols; ++c) {
		for (int r = 0; r < rows; ++r) {
			cells[c][r]->render ();
		}
	}
}
