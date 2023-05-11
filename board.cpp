#include "board.h"

Piece* STANDARD_BOARD[NUM_ROWS][NUM_COLS] =
{
   { &Space(Position(0, 0)), &Space(Position(0, 1)), &Space(Position(0, 2)), &Space(Position(0, 3)), &King(Position(0, 4), false), &Space(Position(0, 5)), &Space(Position(0, 6)), &Space(Position(0, 7)) },
   { &Space(Position(1, 0)), &Space(Position(1, 1)), &Space(Position(1, 2)), &Space(Position(1, 3)), &Space(Position(1, 4)), &Space(Position(1, 5)), &Space(Position(1, 6)), &Space(Position(1, 7)) },
   { &Space(Position(2, 0)), &Space(Position(2, 1)), &Space(Position(2, 2)), &Space(Position(2, 3)), &Space(Position(2, 4)), &Space(Position(2, 5)), &Space(Position(2, 6)), &Space(Position(2, 7)) },
   { &Space(Position(3, 0)), &Space(Position(3, 1)), &Space(Position(3, 2)), &Space(Position(3, 3)), &Space(Position(3, 4)), &Space(Position(3, 5)), &Space(Position(3, 6)), &Space(Position(3, 7)) },
   { &Space(Position(4, 0)), &Space(Position(4, 1)), &Space(Position(4, 2)), &Space(Position(4, 3)), &Space(Position(4, 4)), &Space(Position(4, 5)), &Space(Position(4, 6)), &Space(Position(4, 7)) },
   { &Space(Position(5, 0)), &Space(Position(5, 1)), &Space(Position(5, 2)), &Space(Position(5, 3)), &Space(Position(5, 4)), &Space(Position(5, 5)), &Space(Position(5, 6)), &Space(Position(5, 7)) },
   { &Space(Position(6, 0)), &Space(Position(6, 1)), &Space(Position(6, 2)), &Space(Position(6, 3)), &Space(Position(6, 4)), &Space(Position(6, 5)), &Space(Position(6, 6)), &Space(Position(6, 7)) },
   { &Space(Position(7, 0)), &Space(Position(7, 1)), &Space(Position(7, 2)), &Space(Position(7, 3)), &Space(Position(7, 4)), &Space(Position(7, 5)), &Space(Position(7, 6)), &Space(Position(7, 7)) }
};

/***********************************************
 * DEFAULT CONSTRUCTOR
 * Create a standard board
 ************************************************/
Board::Board() : currentMove(0)
{
   for (int r = 0; r < NUM_ROWS; r++)
   {
      for (int c = 0; c < NUM_COLS; c++)
      {
         pieces[r][c] = STANDARD_BOARD[r][c];
      }
   }
}

/***********************************************
 * NON-DEFAULT CONSTRUCTOR
 * Create a board using a template
 ************************************************/
//Board::Board(Piece* boardTemplate[NUM_ROWS][NUM_COLS]) : currentMove(0)
//{
   //for (int r = 0; r < NUM_ROWS; r++)
   //{
   //   for (int c = 0; c < NUM_COLS; c++)
   //   {
   //      pieces[r][c] = boardTemplate[r][c];
   //   }
   //}
//}

/***********************************************
 * PLACE PIECE
 * Insert a piece to the board, deleting whatever was in its place
 ************************************************/
void Board::setToEmpty()
{
   for (int r = 0; r < NUM_ROWS; r++)
   {
      for (int c = 0; c < NUM_COLS; c++)
      {
         pieces[r][c] = new Space(Position(r, c));
      }
   }
}

/***********************************************
 * PLACE PIECE
 * Insert a piece to the board, deleting whatever was in its place
 ************************************************/
void Board::placePiece(Piece* piece)
{
   int r = piece->getPosition().getRow();
   int c = piece->getPosition().getCol();

   pieces[r][c] = piece;
}

/***********************************************
 * FREE
 * Free up all the memory being used by board
 ************************************************/
void Board::free()
{
   for (auto piece : pieces)
      delete piece;
}

/***********************************************
 * SQUARE BRACKET OPERATOR
 * Find a piece at a given index
 ************************************************/
Piece& Board::operator[](Position & pos)
{
   return *pieces[pos.getRow()][pos.getCol()];
}
const Piece& Board::operator[](Position & pos) const
{
   return *pieces[pos.getRow()][pos.getCol()];
}

const Piece& Board::getPiece(Position pos) const
{
   return *pieces[pos.getRow()][pos.getCol()];
}