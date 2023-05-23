/***********************************************************************
 * Header File:
 *    Bishop
 * Author:
 *    Jenna Scholl
 * Summary:
 *    All the unique functionality of the bishop
 ************************************************************************/

#pragma once

#include "piece.h"

 /*********************************************
  * BISHOPS
  * The resident clergy
  *********************************************/
class Bishop : public Piece
{
public:
   Bishop() : Piece() { }
   Bishop(Position pos, bool isWhite = false) : Piece(pos, isWhite) { }
   const PieceType & getType() const { return BISHOP; }
   void display(ogstream& gout) { gout.drawBishop(position.getLocation(), !fWhite); }
   set<Move> getMoves(const Board& board);
};