/*
 * King.h
 *
 *  Created on: Dec 30, 2016
 *      Author: helarabawy
 */

#ifndef KING_H_
#define KING_H_

	// including Piece header
	#include "../Chess-Game/Piece.h"

	class King : public Piece
	{
		public:

			// Constructor
			King(int player, Grid* grid);

			// Deconstructor
			~King();

			// Public functions
			char getType();
			char getPlayer();
			bool movePiece(int r1, int c1, int r2, int c2);

		private:

			// Private variables
			Grid* gridptr;
			char m_type;
			char m_player;
	};


#endif /* KING_H_ */
