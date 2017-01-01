/*
 * Piece.h
 *
 *  Created on: Dec 30, 2016
 *      Author: helarabawy
 */

#ifndef PIECE_H_
#define PIECE_H_

	// including packages
	#include <cmath>
	#include <string>

	// including headers
	#include "Game.h"
	#include "Grid.h"

	using namespace std;

	class Piece
	{
		public:

			// Constructor
			Piece();

			// Deconstructor
			~Piece();

			// Public functions
			char virtual getType() = 0;
			char virtual getPlayer() = 0;
			bool virtual movePiece(int r1, int c1, int r2, int c2) = 0;
	};


#endif /* PIECE_H_ */
