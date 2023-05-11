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
#include "space.h"
#include "king.h"
#include "uiDraw.h"

const int NUM_ROWS = 8;
const int NUM_COLS = 8;

class Piece;

extern Piece* STANDARD_BOARD[NUM_ROWS][NUM_COLS];

/*********************************************
 * BOARD
 * Where all the pieces are placed
 *********************************************/
class Board
{
private:
   Piece* pieces[8][8];
   int currentMove;
   //ogstream gout;

public:
   Board();
   Board(Piece* boardTemplate[NUM_ROWS][NUM_COLS]);
   void placePiece(Piece* piece);
   Piece& operator[](Position & pos);
   const Piece& operator[](Position & pos) const;
   const Piece& getPiece(Position pos) const;
   void setToEmpty();
   //int const getCurrentMove() { return currentMove; }
   //bool whiteTurn() { return currentMove % 2; }
   //void display(Position posHover, Position posSelect);
   void free();
   //void reset();
   //void move(Move move);
   //void operator=(Piece piece);
   //void swap(Position pos1, Position pos2);
   //void assertBoard();
};