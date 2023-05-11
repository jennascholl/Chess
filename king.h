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
   King() : Piece() { }
   King(Position pos, bool isWhite = false) : Piece(pos, isWhite) { }
   //char getLetter();
   //void display(ogstream gout);
   set<Move> getMoves(Board* board) { return set<Move>(); }
};