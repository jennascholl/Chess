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
	friend TestPawn;
public:
   Pawn() : Piece() { }
   Pawn(Position pos, bool isWhite = false) : Piece(pos, isWhite) { }
   const PieceType & getType() const { return PAWN; }
   void display(ogstream& gout) { gout.drawPawn(position.getLocation(), !fWhite); }
   set<Move> getMoves(const Board & board);


};


