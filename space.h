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
   Space(Position pos) : Piece() { position = pos; fWhite = false; pieceType = SPACE; }
   //char getLetter();
   //void display(ogstream gout);
   //set<Move> getMoves(Board* board, Move move) { return set<Move>(); }
};