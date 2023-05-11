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

extern Piece* STANDARD_BOARD[NUM_ROWS][NUM_COLS];

/*********************************************
 * BOARD
 * Where all the pieces are placed
 *********************************************/
class Board
{
private:
   Piece* board[8][8];
   int currentMove;
   //ogstream gout;

public:
   //Board(ogstream& gout);
   Board() : currentMove(0)
   {
      for (int r = 0; r < NUM_ROWS; r++)
      {
         for (int c = 0; c < NUM_COLS; c++)
         {
            board[r][c] = STANDARD_BOARD[r][c];
         }
      }
   }
   Board(Piece* boardTemplate[NUM_ROWS][NUM_COLS]) : currentMove(0)
   {
      for (int r = 0; r < NUM_ROWS; r++)
      {
         for (int c = 0; c < NUM_COLS; c++)
         {
            board[r][c] = boardTemplate[r][c];
         }
      }
   }
   void placePiece(Piece* piece);
   //int const getCurrentMove() { return currentMove; }
   //bool whiteTurn() { return currentMove % 2; }
   //void display(Position posHover, Position posSelect);
   void free();
   //void reset();
   //void move(Move move);
   //Piece* operator[](Position pos) { return board[pos.getRow()][pos.getCol()]; };
   //void operator=(Piece piece);
   //void swap(Position pos1, Position pos2);
   //void assertBoard();
};