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
   const char getLetter() const { return 'r'; }
   void display(ogstream& gout) { gout.drawKnight(position.getLocation(), !fWhite); }
   set<Move> getMoves(const Board& board) { return set<Move>(); }
};