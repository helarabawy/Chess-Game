/*
* Knight.h
*
*  Created on: Dec 30, 2016
*      Author: helarabawy
*/

#ifndef KNIGHT_H_
#define KNIGHT_H_

// including Piece header
#include "Piece.h"

class Knight : public Piece
{
	public:

		// Constructor
		Knight(char player, Grid* grid);

		// Deconstructor
		~Knight();

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



#endif /* KNIGHT_H_ */
