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

/*********************************************
 * KING
 * The most important piece in the game
 *********************************************/
class King : public Piece
{
   friend TestKing;

public:
   King(const Position & pos, bool isWhite);
   char getLetter();
   void display(ogstream gout);
   set<Move> getMoves(Board* board, Move move);
};