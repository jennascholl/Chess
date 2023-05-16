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

void Board::reset()
{
   for (int r = 2; r < 6; r++)
      for (int c = 0; c < 8; c++)
         pieces[r][c] = new Space(Position(r, c));

   for (int c = 0; c < 8; c++)
   {
      pieces[1][c] = new Pawn(Position(1, c), true);
      pieces[6][c] = new Pawn(Position(6, c), false);
   }

   currentMove = 0;
}

void Board::display(const Position& posHover, const Position& posSelect)
{
   gout.drawBoard();
   gout.drawHover(posHover.getLocation());
   gout.drawSelected(posSelect.getLocation());

   // draw the possible moves
   if (posSelect.isValid())
   {
      set<Move> possible = (*this)[posSelect].getMoves(*this);
      for (auto it = possible.begin(); it != possible.end(); it++)
         gout.drawPossible(it->getDest().getLocation());
   }

   //for (int r = 0; r < 8; r++)
   //   for (int c = 0; c < 8; c++)
   //      (*pieces[r][c]).display(gout);

}

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
   for (auto & piece : pieces)
      delete *piece;
}

/***********************************************
 * SQUARE BRACKET OPERATOR
 * Find a piece at a given index
 ************************************************/
Piece& Board::operator[](const Position & pos)
{
   return *pieces[pos.getRow()][pos.getCol()];
}

const Piece& Board::operator[](const Position & pos) const
{
   return *pieces[pos.getRow()][pos.getCol()];
}