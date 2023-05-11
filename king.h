/***********************************************************************
 * Header File:
 *    King
 * Author:
 *    Jenna Scholl
 * Summary:
 *    All the unique functionality of the king
 ************************************************************************/

#pragma once

#include "piece.h"

class TestKing;
class Board;

/*********************************************
 * KING
 * The most important piece in the game
 *********************************************/
class King : public Piece
{
   friend TestKing;
public:
   King() : Piece() { }
   King(Position pos, bool isWhite = false) : Piece(pos, isWhite) { }
   const char getLetter() const { return 'k'; }
   //char getLetter();
   //void display(ogstream gout);
   set<Move> getMoves(const Board & board);
};