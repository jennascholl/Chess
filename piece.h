#pragma once

#include "position.h"
#include "move.h"
#include <set>

using namespace std;

class Board;

enum type { KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN, SPACE };

class Piece
{
protected:
   Position position;
   bool fWhite;
   int numMoves;
   int lastMove;

public:
   Piece() : position(Position(0, 0)), 
             fWhite(true), numMoves(0), lastMove(0) { }
   Piece(Position pos, bool isWhite) : position(pos), fWhite(isWhite) { numMoves = 0; lastMove = 0; }
   //void operator=(Position pos);
   //void operator=(Piece piece);
   //bool isWhite() { return fWhite; }
   //bool isMoved() { return numMoves; }
   //int getNMoves() { return numMoves; }
   Position getPosition() { return position; }
 /*  bool justMoved();*/
   //virtual type getType() = 0;
   //virtual void display(ogstream gout) = 0;
   virtual set<Move> getMoves(Board* board) = 0;
};