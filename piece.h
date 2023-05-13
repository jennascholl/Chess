#pragma once

#include "move.h"

#include <set>
#include <array>

using namespace std;

class Board;

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
   const bool isWhite() const { return fWhite; }
   const bool isMoved() const { return numMoves; }
   const int getNMoves() const { return numMoves; }
   Position getPosition() { return position; }
   const bool justMoved(int move) const { return move - lastMove <= 2; }
   //virtual type getType() = 0;
   //virtual void display(ogstream gout) = 0;
   virtual const char getLetter() const = 0;
   virtual set<Move> getMoves(const Board& board) = 0;
   set<Move>  getMovesNoSlide(const Board& board, array<Delta, 8> deltas);
   set<Move>  getMovesSlide(const Board& board, array<Delta, 8> deltas);
};