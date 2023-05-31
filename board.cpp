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

/***********************************************
 * RESET
 * Set up the board for a new game
 ************************************************/
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

/***********************************************
 * DISPLAY
 * Draw the board and everything on it
 ************************************************/
void Board::display(const Position& posHover, const Position& posSelect)
{
   gout.drawBoard();
   gout.drawHover(posHover.getLocation());

   // only display valid move options
   if ((*this)[posSelect].isWhite() == whiteTurn() && (*this)[posSelect].getType() != SPACE)
   {
      gout.drawSelected(posSelect.getLocation());

      // draw the possible moves
      if (posSelect.isValid())
      {
         set<Move> possible = (*this)[posSelect].getMoves(*this);
         for (auto it = possible.begin(); it != possible.end(); it++)
            gout.drawPossible(it->getDes().getLocation());
      }
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
   move.complete(*this); // get all the necessary context
   Position src = move.getSrc(); 
   Position des = move.getDes();
    
   // just double checking
   this->assertBoard();
   assert(src.isValid());
   assert(des.isValid());
   assert((*this)[src].isWhite() == this->whiteTurn());

   // capture
   if (move.getCapture() != SPACE)
   {
      // verify the state of the pieces
      assert((*this)[des].getType() != SPACE);
      assert((*this)[src].isWhite() != (*this)[des].isWhite());

      // kill the opponent and take its place
      *this -= &(*this)[des];
      swap(src, des);
   }
   // promote
   else if(move.getPromotion() != NULL)
   {
      // verify the state of the pieces
      assert(des.getRow() == (*this)[des].isWhite() ? 0 : 7);
      assert((*this)[des].getType() == SPACE);

      // promote ourselves and make the move
      switch (move.getPromotion())
      {
      case QUEEN:
         *this += new Queen(Position(src.getRow(), src.getCol()), move.getWhiteMove());
         break;
      case ROOK:
         *this += new Rook(Position(src.getRow(), src.getCol()), move.getWhiteMove());
         break;
      case KNIGHT:
         *this += new Knight(Position(src.getRow(), src.getCol()), move.getWhiteMove());
         break;
      case BISHOP:
         *this += new Bishop(Position(src.getRow(), src.getCol()), move.getWhiteMove());
         break;
      default:
         assert(false); // promotion is mandatory
      }

      swap(src, des);
   }
   // en-passant
   else if (move.getEnPassant())
   {
      // verify the state of the pieces
      assert(pieces[src.getRow()][des.getCol()]->getType() == PAWN);
      assert(pieces[des.getRow()][des.getCol()]->getType() == SPACE);
      assert(pieces[src.getRow()][des.getCol()]->getNMoves() == 1);

      // kill our opponent and make the move
      *this -= &(*this)[Position(src.getRow(), des.getCol())];
      swap(src, des);
   }
   // king's castle
   else if (move.getCastleK())
   {
      // verify the state of the pieces
      assert((*this)[src].getNMoves() == 0);
      assert(pieces[src.getRow()][des.getCol() + 1]->getNMoves() == 0);

      // move the king, then the rook
      swap(src, des);
      src.adjustCol(3);
      des.adjustCol(-1);
      swap(src, des);
   }
   // queen's castle
   else if (move.getCastleQ())
   {
      // verify the state of the pieces
      assert((*this)[src].getNMoves() == 0);
      assert(pieces[src.getRow()][des.getCol() - 2]->getNMoves() == 0);

      // move the king, then the rook
      swap(src, des);
      src.adjustCol(-4);
      des.adjustCol(1);
      swap(src, des);
   }
   // standard move
   else
   {
      swap(src, des);
   }

   currentMove++;
   this->assertBoard(); // make sure we didn't break anything
}

/****************************************
*  SWAP
*  Swap pieces at locations
*****************************************/
void Board::swap(Position pos1, Position pos2)
{
    // swap the positions
    (*this)[pos1] = pos2;
    (*this)[pos2] = pos1;

    // swap the pointers
    Piece* temp = pieces[pos1.getRow()][pos1.getCol()];
    pieces[pos1.getRow()][pos1.getCol()] = pieces[pos2.getRow()][pos2.getCol()];
    pieces[pos2.getRow()][pos2.getCol()] = temp;

    // update each piece's last move
    (*this)[pos1].setLastMove(currentMove);
    (*this)[pos2].setLastMove(currentMove);

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

   delete pieces[r][c];

   pieces[r][c] = new Space(Position(r, c));
}

/***********************************************
 * ADD OPERATOR
 * Replace a piece with a space, deleting whatever was in its place
 ************************************************/
void Board::operator+=(Piece* piece)
{
   int r = piece->getPosition().getRow();
   int c = piece->getPosition().getCol();

   delete pieces[r][c];

   pieces[r][c] = piece;
}

/***********************************************
 * ASSERT BOARD
 * Make sure every piece is where it thinks it is
 ************************************************/
void Board::assertBoard()
{
   for (int r = 0; r < NUM_ROWS; r++)
      for (int c = 0; c < NUM_COLS; c++)
      {
         Position piecePos = pieces[r][c]->getPosition();
         assert(r == piecePos.getRow());
         assert(c == piecePos.getCol());

         // nothing should be null
         assert(pieces[r][c]->getType() == SPACE ||
             pieces[r][c]->getType() == KING ||
             pieces[r][c]->getType() == QUEEN ||
             pieces[r][c]->getType() == ROOK ||
             pieces[r][c]->getType() == BISHOP ||
             pieces[r][c]->getType() == KNIGHT ||
             pieces[r][c]->getType() == PAWN);
      }
}