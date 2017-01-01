/*
 * Grid.h
 *
 *  Created on: Dec 22, 2016
 *      Author: helarabawy
 */

#ifndef GRID_H_
#define GRID_H_

// Headers to include
#include <iostream>
#include <string>
#include <cctype>

using namespace std;
class Piece;

// Class declaration
class Grid
{
	public:

		// Constructor
		Grid();

		// Destructor
		~Grid();

		// Public functions
		void setUp();
		int makeMove(string input, int player);
		void display();
		string getCellInfo(int r,int c);
		bool isDone();
		string getWinner();

	private:

		// Private variables
		Piece* grid[10][10]; //extra rows and cols for gutter
		int m_nWhite;
		int m_nBlack;
};


#endif /* GRID_H_ */
