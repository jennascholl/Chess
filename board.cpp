#include "board.h"
using namespace std;


/***********************************************
 * DEFAULT CONSTRUCTOR
 * Create a standard board
 ************************************************/
Board::Board() : currentMove(0)
{
   reset();
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

   // white side
   pieces[0][0] = new Rook(Position(0, 0), true);
   pieces[0][1] = new Knight(Position(0, 1), true);
   pieces[0][2] = new Bishop(Position(0, 2), true);
   pieces[0][3] = new Queen(Position(0, 3), true);
   pieces[0][4] = new King(Position(0, 4), true);
   pieces[0][5] = new Bishop(Position(0, 5), true);
   pieces[0][6] = new Knight(Position(0, 6), true);
   pieces[0][7] = new Rook(Position(0, 7), true);

   // black side
   pieces[7][0] = new Rook(Position(7, 0), false);
   pieces[7][1] = new Knight(Position(7, 1), false);
   pieces[7][2] = new Bishop(Position(7, 2), false);
   pieces[7][3] = new Queen(Position(7, 3), false);
   pieces[7][4] = new King(Position(7, 4), false);
   pieces[7][5] = new Bishop(Position(7, 5), false);
   pieces[7][6] = new Knight(Position(7, 6), false);
   pieces[7][7] = new Rook(Position(7, 7), false);

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
         gout.drawPossible(it->getDes().getLocation());
   }

   for (int r = 0; r < 8; r++)
      for (int c = 0; c < 8; c++)
         pieces[r][c]->display(gout);

}

/***********************************************
 * SET TO EMPTY
 * Set every spot on the board to a space
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
 * Move
 * Move the desired pieces in board.
 ************************************************/
void Board::move(Move move)
{
    //Move has source and destination. Switch places?  
    Position src = move.getSrc();
    int srcR = src.getRow();
    int srcC = src.getCol();


    Position dest = move.getDes();
    Position storePos = move.getDes();

    int destR = dest.getRow();
    int destC = dest.getCol();

    //update piece location to destination // Can't find way to update it?
    swap(src, dest);
    
}

/****************************************
*  SWAP
*  Swap pieces at locations. 
*****************************************/
void Board::swap(Position pos1, Position pos2)
{

    //Swap Pieces
    Piece* p = (*this).pieces[pos1.getRow()][pos1.getCol()];
    (*this).pieces[pos1.getRow()][pos1.getCol()] = (*this).pieces[pos2.getRow()][pos2.getCol()];
    (*this).pieces[pos2.getRow()][pos2.getCol()] = p;

    //Swap pointers?
    Position storePos = pos1;
    (*pieces[pos1.getRow()][pos1.getCol()]) = pos2;
    (*pieces[pos2.getRow()][pos2.getCol()]) = storePos;

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


/***********************************************
 * SUBTRACT OPERATOR
 * Replace a piece with a space, deleting whatever was in its place
 ************************************************/
void Board::operator -= (Piece* piece)
{
    int r = piece->getPosition().getRow();
    int c = piece->getPosition().getCol();

    Space* space;

    pieces[r][c] = space;
}