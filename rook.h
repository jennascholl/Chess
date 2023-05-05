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
   Rook(Position pos, bool isWhite);
   char getLetter();
   void display(ogstream gout);
   set<Move> getMoves(Board* board, Move move);
};