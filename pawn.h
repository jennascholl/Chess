/***********************************************************************
 * Header File:
 *    Pawn
 * Author:
 *    Jenna Scholl
 * Summary:
 *    All the unique functionality of the pawn
 ************************************************************************/

#pragma once

#include "piece.h"

/*********************************************
 * PAWN
 * The most common piece in the game
 *********************************************/
class Pawn : public Piece
{
public:
   Pawn(Position pos, bool isWhite);
   char getLetter();
   void display(ogstream gout);
   set<int> getMoves(Board board);
};
