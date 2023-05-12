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

class TestPawn;
class Board;

/*********************************************
 * PAWN
 * The most common piece in the game
 *********************************************/
class Pawn : public Piece
{
	//friend TestPawn;

public:
   Pawn() : Piece() { }
   Pawn(const Position& pos, bool isWhite = false) : Piece(pos, isWhite) { }
   const char getLetter() const { return 'p'; }
   //void display(ogstream gout);
   set<Move> getMoves(const Board& board);


};


