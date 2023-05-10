#pragma once

#include "position.h"
#include "uiDraw.h"
#include "board.h"
#include <set>

using namespace std;

class Piece
{
protected:
   Position position;
   bool fWhite;
   int numMoves = 0;
   int lastMove = 0;

public:
	//I corrected white to isWhite
	//Need to make position default constructor
	Piece(Position pos, bool isWhite)
	{
		this->position = pos;
		this->fWhite = isWhite;
	};

   void operator=(Position pos);
   void operator=(Piece piece);
   bool isWhite() { return fWhite; }
   bool isMove();
   int getNMoves() { return numMoves; }
   Position getPosition() { return position; }
   bool justMoved();
   virtual char getLetter() = 0;
   virtual void display(ogstream gout) = 0;
   virtual set<Move> getMoves(Board* board, Move move) = 0;
};