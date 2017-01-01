/*
 * Game.h
 *
 *  Created on: Dec 22, 2016
 *      Author: helarabawy
 */

#ifndef GAME_H_
#define GAME_H_

// Packages to include
#include <iostream>
#include <string>
#include <cctype>

// Constants
const char PLAYER_WHITE = 'w';
const char PLAYER_BLACK = 'b';


// Headers to include
#include "Grid.h"

using namespace std;

// Class declaration
class Game
{
	public:

		// Constructor
		Game();

		// Destructor
		~Game();

		// Public functions
		void start();

	private:

		// Private variables
		Grid chessGrid;
};


#endif /* GAME_H_ */
