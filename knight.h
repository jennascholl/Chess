/***********************************************************************
 * Header File:
 *    Knight
 * Author:
 *    Jenna Scholl
 * Summary:
 *    All the unique functionality of the knight
 ************************************************************************/

#pragma once

#include "piece.h"

/*********************************************
 * KNIGHT
 * The most unique piece in the game
 *********************************************/
class Knight : public Piece
{
public:
   Knight() : Piece() { }
   Knight(Position pos, bool isWhite = false) : Piece(pos, isWhite) { }
   const PieceType & getType() const { return KNIGHT; }
   void display(ogstream& gout) { gout.drawKnight(position.getLocation(), !fWhite); }
   set<Move> getMoves(const Board& board);
};