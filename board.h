/***********************************************************************
 * Header File:
 *    Board
 * Author:
 *    Jenna Scholl
 * Summary:
 *    Everything we need to know about the chess board
 ************************************************************************/

#pragma once

#include "piece.h"
#include "pawn.h"
#include "space.h"
#include "king.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "uiDraw.h"
#include <cassert>

const int NUM_ROWS = 8;
const int NUM_COLS = 8;

class Piece;

/*********************************************
 * BOARD
 * Where all the pieces are placed
 *********************************************/
class Board
{
private:
   Piece* pieces[8][8];
   int currentMove;
   ogstream gout;

public:
   Board();
   Piece& operator[](const Position & pos);
   const Piece& operator[](const Position & pos) const;
   void setToEmpty();
   const int getCurrentMove() const { return currentMove; }
   bool whiteTurn() { return currentMove % 2; }
   void display(const Position& posHover, const Position& posSelect);
   void free();
   void reset();
   void move(Move move);
   //void operator=(Piece piece);
   void operator -= (Piece* piece);
   void operator += (Piece* piece);
   void swap(Position pos1, Position pos2);
   void assertBoard();
};