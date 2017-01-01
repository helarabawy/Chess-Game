/*
* Bishop.h
*
*  Created on: Dec 30, 2016
*      Author: helarabawy
*/

#ifndef BISHOP_H_
#define BISHOP_H_

// including Piece header
#include "Piece.h"

class Bishop : public Piece
{
	public:

		// Constructor
		Bishop(char player, Grid* grid);

		// Deconstructor
		~Bishop();

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



#endif /* BISHOP_H_ */
