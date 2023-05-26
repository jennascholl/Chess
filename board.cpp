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
    Position src = move.getSrc(); //Do they need to be pointers?
    Position des = move.getDes();
    
    this->assertBoard();
    //swap(src, des);   //Default  

    //check that both moves are valid
    //check that it's the correct turn -> check isWhite from src position  / see if match white
    if ((src.isValid() && des.isValid()) &&
     pieces[src.getRow()][src.getCol()]->isWhite() == this->whiteTurn())
    {
        //if it's a pawn, can capture, and it's on the last row the promote.
        if (pieces[src.getRow()][src.getCol()]->getType() == PAWN
            && (des.getRow() == 0 || des.getRow() == 7))
        {
            move.getPromotion();
            bool isPawnWhite = pieces[src.getRow()][src.getCol()]->isWhite();

            Queen* queen = new Queen(src, isPawnWhite);

            *this += queen;

        }

        // capture
        //double check the state of the pieces
        //If It's landing on a space, different color, and not a king, then take it.
        if (pieces[des.getRow()][des.getCol()]->getType() != SPACE
            && pieces[des.getRow()][des.getCol()]->getType() != KING
            && pieces[src.getRow()][src.getCol()]->isWhite() !=
            pieces[des.getRow()][des.getCol()]->isWhite())
        {
            //kill the victim using -=
            //move the attacker using swap
            *this -= pieces[des.getRow()][des.getCol()];
            swap(src, des);   //Default
        }
        else
            //if (promote)
        {
            swap(src, des);
        }
        
        //if it's a pawn, can capture, and it's on the last row the promote.
        if (pieces[src.getRow()][src.getCol()]->getType() == PAWN
            && (des.getRow() == 0 || des.getRow() == 7))
        {
            move.getPromotion();
        }
        


        // enpassant
            //double check the state of the pawns
            //kill the other pawn using -=
            //move the pawn using swap

        // promote
        //check that we are a pawnand in the last row
        //kill the pawn using -=
        //add the promoted piece to the board using placePiece

        // king's castle
        //check that kingand rook are in the right positions
        //set the row depending on whose move it is
        //move the kingand the rook using swap(set srcand des manually)

        // queen's castle
        //check that king and rook are in the right positions
        //set the row depending on whose move it is
        //move the kingand the rook using swap(set srcand des manually

        // default
        //double check the state of the piece
        //move the piece using swap

        this->assertBoard();
   }
}

/****************************************
*  SWAP
*  Swap pieces at locations. 
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

void Board::assertBoard()
{
   for (int r = 0; r < NUM_ROWS; r++)
      for (int c = 0; c < NUM_COLS; c++)
      {
         Position piecePos = pieces[r][c]->getPosition();
         assert(r == piecePos.getRow());
         assert(c == piecePos.getCol());

         assert(pieces[r][c]->getType() == SPACE ||
             pieces[r][c]->getType() == KING ||
             pieces[r][c]->getType() == QUEEN ||
             pieces[r][c]->getType() == ROOK ||
             pieces[r][c]->getType() == BISHOP ||
             pieces[r][c]->getType() == KNIGHT ||
             pieces[r][c]->getType() == PAWN);
      }

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