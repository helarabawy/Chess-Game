/*
 * Queen.h
 *
 *  Created on: Dec 30, 2016
 *      Author: helarabawy
 */

#ifndef QUEEN_H_
#define QUEEN_H_

	// including Piece header
	#include "../Chess-Game/Piece.h"

	class Queen : public Piece
	{
		public:

			// Constructor
			Queen(int player, Grid* grid);

			// Deconstructor
			~Queen();

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


#endif /* QUEEN_H_ */
