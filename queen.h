/***********************************************************************
 * Header File:
 *    Queen
 * Author:
 *    Jenna Scholl
 * Summary:
 *    All the unique functionality of the queen
 ************************************************************************/

#pragma once

#include "piece.h"

/*********************************************
 * QUEEN
 * The most powerful piece in the game
 *********************************************/
class Queen : public Piece
{
public:
   Queen() : Piece() { }
   Queen(Position pos, bool isWhite = false) : Piece(pos, isWhite) { }
   const PieceType & getType() const { return QUEEN; }
   void display(ogstream& gout) { gout.drawQueen(position.getLocation(), !fWhite); }
   set<Move> getMoves(const Board& board);
};