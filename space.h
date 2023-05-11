/***********************************************************************
 * Header File:
 *    Space
 * Author:
 *    Jenna Scholl
 * Summary:
 *    All the unique functionality of the space
 ************************************************************************/

#pragma once

#include "piece.h"

/*********************************************
 * SPACE
 * An empty spot on the board
 *********************************************/
class Space : public Piece
{
public:
   Space() : Piece() { }
   Space(Position pos, bool isWhite = false) : Piece(pos, isWhite) { }
   //char getLetter();
   //void display(ogstream gout);
   set<Move> getMoves(Board* board) { return set<Move>(); }
};