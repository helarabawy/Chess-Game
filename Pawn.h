/*
* Pawn.h
*
*  Created on: Dec 30, 2016
*      Author: helarabawy
*/

#ifndef PAWN_H_
#define PAWN_H_

// including Piece header
#include "Piece.h"

class Pawn : public Piece
{
	public:

		// Constructor
		Pawn(char player, Grid* grid);

		// Deconstructor
		~Pawn();

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


#endif /* PAWN_H_ */
