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

// a default setup for the board
//Piece* DEFAULT_BOARD[NUM_ROW][NUM_COL] = {
//         {Rook(RC(0, 0), 0), Bishop(RC(0, 1), 0), Knight(RC(0, 2), 0), Queen(RC(0, 3), 0), King(RC(0, 4), 0), Knight(RC(0, 5), 0), Bishop(RC(0, 6), 0), Rook(RC(0, 7), 0)},
//         {Pawn(RC(1, 0), 0), Pawn(RC(1, 1), 0), Pawn(RC(1, 2), 0), Pawn(RC(1, 3), 0), Pawn(RC(1, 4), 0), &Pawn(RC(1, 5), 0), &Pawn(RC(1, 6), 0), Pawn(RC(1, 7), 0)},
//         {Space(RC(2, 0)), Space(RC(2, 1)), Space(RC(2, 2)), Space(RC(2, 3)), Space(RC(2, 4)), Space(RC(2, 5)), Space(RC(2, 6)), Space(RC(2, 7))},
//         {Space(RC(3, 0)), Space(RC(3, 1)), Space(RC(3, 2)), Space(RC(3, 3)), Space(RC(3, 4)), Space(RC(3, 5)), Space(RC(3, 6)), Space(RC(3, 7))},
//         {Space(RC(4, 0)), Space(RC(4, 1)), Space(RC(4, 2)), Space(RC(4, 3)), Space(RC(4, 4)), Space(RC(4, 5)), Space(RC(4, 6)), Space(RC(4, 7))},
//         {Space(RC(5, 0)), Space(RC(5, 1)), Space(RC(5, 2)), Space(RC(5, 3)), Space(RC(5, 4)), Space(RC(5, 5)), Space(RC(5, 6)), Space(RC(5, 7))},
//         {Pawn(RC(6, 0), 1), &Pawn(RC(6, 1), 1), Pawn(RC(6, 2), 1), Pawn(RC(6, 3), 1), &Pawn(RC(6, 4), 1), &Pawn(RC(6, 5), 1), Pawn(RC(6, 6), 1), Pawn(RC(6, 7), 1)},
//         {Rook(RC(7, 0), 1), Bishop(RC(7, 1), 1), Knight(RC(7, 2), 1), Queen(Position(7, 3), 1), King(Position(7, 4), 1), Knight(RC(7, 5), 1), Bishop(RC(7, 6), 1), Rook(RC(7, 7), 1)} };

/*********************************************
 * BOARD
 * Where all the pieces are placed
 *********************************************/
class Board
{
private:
   Piece* board[8][8];
   int currentMove;
   ogstream gout;

public:
   Board(ogstream& gout);
   Board(Piece* boardTemplate[8][8]);
   void placePiece(Piece* piece);
   int getCurrentMove() { return currentMove; }
   bool whiteTurn() { return currentMove % 2; }
   void display(Position posHover, Position posSelect);
   Piece* get(Position pos);
   void free();
   void reset();
   void move(Move move);
   void operator=(Piece piece);
   void swap(Position pos1, Position pos2);
   void assertBoard();
};