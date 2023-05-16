/***********************************************************************
 * Header File:
 *    Rook
 * Author:
 *    Jenna Scholl
 * Summary:
 *    All the unique functionality of the rook
 ************************************************************************/

#pragma once

#include "piece.h"

class TestKing;

 /*********************************************
  * ROOK
  * I literally don't know what a rook is
  *********************************************/
class Rook : public Piece
{
   friend TestKing;
public:
   Rook() : Piece() { }
   Rook(Position pos, bool isWhite = false) : Piece(pos, isWhite) { }
   const char getLetter() const { return 'r'; }
   void display(ogstream& gout) { gout.drawRook(position.getLocation(), !fWhite); }
   set<Move> getMoves(const Board& board) { return set<Move>(); }
};