#pragma once

#include "move.h"
#include "pieceType.h"
#include "uiDraw.h"

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
   void operator=(const Position pos);
   //void operator=(const Piece* piece);
   bool isWhite() const { return fWhite; }
   bool isMoved() const { return numMoves; }
   int getNMoves() const { return numMoves; }
   int getLastMove() const { return lastMove; }
   void setLastMove(int currentMove) { lastMove = currentMove; }
   const Position & getPosition() const { return position; }
   bool justMoved(int move) const { return move - lastMove <= 2; }
   virtual void display(ogstream& gout) = 0;
   virtual const PieceType & getType() const = 0;
   virtual set<Move> getMoves(const Board& board) = 0;
   set<Move> getMovesNoSlide(const Board& board, const Delta deltas[], int numDeltas) const;
   set<Move> getMovesSlide(const Board& board, const Delta deltaa[], int numDeltas) const;
};