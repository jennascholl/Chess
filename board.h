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
#include "move.h"
#include "uiDraw.h"

const int NUM_ROWS = 8;
const int NUM_COLS = 8;

class Piece;
class Space;

//Piece* EMPTY_BOARD[NUM_ROWS][NUM_COLS] =
//{
//   { &Space(Position(0, 0)), &Space(Position(0, 1)), &Space(Position(0, 2)), &Space(Position(0, 3)), &Space(Position(0, 4)), &Space(Position(0, 5)), &Space(Position(0, 6)), &Space(Position(0, 7)) },
//   { &Space(Position(1, 0)), &Space(Position(1, 1)), &Space(Position(1, 2)), &Space(Position(1, 3)), &Space(Position(1, 4)), &Space(Position(1, 5)), &Space(Position(1, 6)), &Space(Position(1, 7)) },
//   { &Space(Position(2, 0)), &Space(Position(2, 1)), &Space(Position(2, 2)), &Space(Position(2, 3)), &Space(Position(2, 4)), &Space(Position(2, 5)), &Space(Position(2, 6)), &Space(Position(2, 7)) },
//   { &Space(Position(3, 0)), &Space(Position(3, 1)), &Space(Position(3, 2)), &Space(Position(3, 3)), &Space(Position(3, 4)), &Space(Position(3, 5)), &Space(Position(3, 6)), &Space(Position(3, 7)) },
//   { &Space(Position(4, 0)), &Space(Position(4, 1)), &Space(Position(4, 2)), &Space(Position(4, 3)), &Space(Position(4, 4)), &Space(Position(4, 5)), &Space(Position(4, 6)), &Space(Position(4, 7)) },
//   { &Space(Position(5, 0)), &Space(Position(5, 1)), &Space(Position(5, 2)), &Space(Position(5, 3)), &Space(Position(5, 4)), &Space(Position(5, 5)), &Space(Position(5, 6)), &Space(Position(5, 7)) },
//   { &Space(Position(6, 0)), &Space(Position(6, 1)), &Space(Position(6, 2)), &Space(Position(6, 3)), &Space(Position(6, 4)), &Space(Position(6, 5)), &Space(Position(6, 6)), &Space(Position(6, 7)) },
//   { &Space(Position(7, 0)), &Space(Position(7, 1)), &Space(Position(7, 2)), &Space(Position(7, 3)), &Space(Position(7, 4)), &Space(Position(7, 5)), &Space(Position(7, 6)), &Space(Position(7, 7)) } 
//};

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

   }
   /*Board(Piece* boardTemplate[8][8]);*/
   //void placePiece(Piece* piece);
   //int const getCurrentMove() { return currentMove; }
   //bool whiteTurn() { return currentMove % 2; }
   //void display(Position posHover, Position posSelect);
   //void free();
   //void reset();
   //void move(Move move);
   //Piece* operator[](Position pos) { return board[pos.getRow()][pos.getCol()]; };
   //void operator=(Piece piece);
   //void swap(Position pos1, Position pos2);
   //void assertBoard();
};