#pragma once

#include "position.h"
#include "uiDraw.h"
#include "board.h"
#include "move.h"
#include <set>

using namespace std;

enum type { KING, QUEEN, ROOK, KNIGHT, BISHOP, PAWN, SPACE };

class Piece
{
protected:
   type pieceType;
   Position position;
   bool fWhite;
   int numMoves;
   int lastMove;

public:
   Piece() : pieceType(SPACE), position(Position(0, 0)), 
             fWhite(true), numMoves(0), lastMove(0) { }
   //void operator=(Position pos);
   //void operator=(Piece piece);
   //bool isWhite() { return fWhite; }
   //bool isMoved() { return numMoves; }
   //int getNMoves() { return numMoves; }
   //Position getPosition() { return position; }
 /*  bool justMoved();*/
   //virtual type getType() = 0;
   //virtual void display(ogstream gout) = 0;
   //virtual set<Move> getMoves(Board* board, Move move) = 0;
};