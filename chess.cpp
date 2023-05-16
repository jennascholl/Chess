/**********************************************************************
 * GL Demo
 * Just a simple program to demonstrate how to create an Open GL window, 
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "uiInteract.h"   // for Interface
#include "uiDraw.h"       // for draw*
#include "test.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "pawn.h"
#include "space.h"
#include "board.h"


#include <set>            // for STD::SET
#include <cassert>        // for ASSERT
#include <fstream>        // for IFSTREAM
#include <string>         // for STRING
using namespace std;

/*********************************************************
 * GET POSSIBLE MOVES
 * Determine all the possible moves for a given chess piece
 *********************************************************/
//set <int> getPossibleMoves(const char* board, int location)
//{
//   set <int> possible;
//
//   // return the empty set if there simply are no possible moves
//   if (location < 0 || location >= 64 || board[location] == ' ')
//      return possible;
//   int row = location / 8;  // current location row
//   int col = location % 8;  // current location column
//   int r;                   // the row we are checking
//   int c;                   // the column we are checking
//   bool amBlack = isBlack(board, row, col);
//
//   //
//   // PAWN
//   //
//   if (board[location] == 'P')
//   {
//      c = col;
//      r = row - 2;
//      if (row == 6 && board[r * 8 + c] == ' ')
//         possible.insert(r * 8 + c);  // forward two blank spaces
//      r = row - 1;
//      if (r >= 0 && board[r * 8 + c] == ' ')
//         possible.insert(r * 8 + c);  // forward one black space
//      c = col - 1;
//      if (isWhite(board, r, c))
//         possible.insert(r * 8 + c);    // attack left
//      c = col + 1;
//      if (isWhite(board, r, c))
//         possible.insert(r * 8 + c);    // attack right
//      // what about en-passant and pawn promotion
//   }
//   if (board[location] == 'p')
//   {
//      c = col;
//      r = row + 2;
//      if (row == 1 && board[r * 8 + c] == ' ')
//         possible.insert(r * 8 + c);  // forward two blank spaces
//      r = row + 1;
//      if (r < 8 && board[r * 8 + c] == ' ')
//         possible.insert(r * 8 + c);    // forward one blank space
//      c = col - 1;
//      if (isBlack(board, r, c))
//         possible.insert(r * 8 + c);      // attack left
//      c = col + 1;
//      if (isBlack(board, r, c))
//         possible.insert(r * 8 + c);      // attack right
//      // what about en-passant and pawn promotion
//   }
//
//   //
//   // KNIGHT
//   //
//   if (board[location] == 'N' || board[location] == 'n')
//   {
//      RC moves[8] = 
//      {
//               {-1,  2}, { 1,  2},
//      {-2,  1},                    { 2,  1},
//      {-2, -1},                    { 2, -1},
//               {-1, -2}, { 1, -2}
//      };
//      for (int i = 0; i < 8; i++)
//      {
//         r = row + moves[i].row;
//         c = col + moves[i].col;
//         if ( amBlack && isNotBlack(board, r, c))
//            possible.insert(r * 8 + c);
//         if (!amBlack && isNotWhite(board, r, c))
//            possible.insert(r * 8 + c);
//      }
//   }
//
//   //
//   // KING
//   //
//   if (board[location] == 'K' || board[location] == 'k')
//   {
//      RC moves[8] =
//      {
//         {-1,  1}, {0,  1}, {1,  1},
//         {-1,  0},          {1,  0},
//         {-1, -1}, {0, -1}, {1, -1}
//      };
//      for (int i = 0; i < 8; i++)
//      {
//         r = row + moves[i].row;
//         c = col + moves[i].col;
//         if ( amBlack && isNotBlack(board, r, c))
//            possible.insert(r * 8 + c);
//         if (!amBlack && isNotWhite(board, r, c))
//            possible.insert(r * 8 + c);
//      }
//      // what about castling?
//   }
//
//   //
//   // QUEEN
//   //
//   if (board[location] == 'Q' || board[location] == 'q')
//   {
//      RC moves[8] =
//      {
//         {-1,  1}, {0,  1}, {1,  1},
//         {-1,  0},          {1,  0},
//         {-1, -1}, {0, -1}, {1, -1}
//      };
//      for (int i = 0; i < 8; i++)
//      {
//         r = row + moves[i].row;
//         c = col + moves[i].col;
//         while (r >= 0 && r < 8 && c >= 0 && c < 8 && 
//                board[r * 8 + c] == ' ')
//         {
//            possible.insert(r * 8 + c);
//            r += moves[i].row;
//            c += moves[i].col;
//         }
//         if ( amBlack && isNotBlack(board, r, c))
//            possible.insert(r * 8 + c);
//         if (!amBlack && isNotWhite(board, r, c))
//            possible.insert(r * 8 + c);
//      }
//   }
//
//   //
//   // ROOK
//   //
//   if (board[location] == 'R' || board[location] == 'r')
//   {
//      RC moves[4] =
//      {
//                  {0,  1},
//         {-1, 0},         {1, 0},
//                  {0, -1}
//      };
//      for (int i = 0; i < 4; i++)
//      {
//         r = row + moves[i].row;
//         c = col + moves[i].col;
//         while (r >= 0 && r < 8 && c >= 0 && c < 8 &&
//            board[r * 8 + c] == ' ')
//         {
//            possible.insert(r * 8 + c);
//            r += moves[i].row;
//            c += moves[i].col;
//         }
//         if (amBlack && isNotBlack(board, r, c))
//            possible.insert(r * 8 + c);
//         if (!amBlack && isNotWhite(board, r, c))
//            possible.insert(r * 8 + c);
//      }
//   }
//
//   //
//   // BISHOP
//   //
//   if (board[location] == 'B' || board[location] == 'b')
//   {
//      RC moves[4] =
//      {
//         {-1,  1}, {1,  1},
//         {-1, -1}, {1, -1}
//      };
//      for (int i = 0; i < 4; i++)
//      {
//         r = row + moves[i].row;
//         c = col + moves[i].col;
//         while (r >= 0 && r < 8 && c >= 0 && c < 8 &&
//            board[r * 8 + c] == ' ')
//         {
//            possible.insert(r * 8 + c);
//            r += moves[i].row;
//            c += moves[i].col;
//         }
//         if (amBlack && isNotBlack(board, r, c))
//            possible.insert(r * 8 + c);
//         if (!amBlack && isNotWhite(board, r, c))
//            possible.insert(r * 8 + c);
//      }
//   }
//
//   return possible;
//}

/***************************************************
 * DRAW
 * Draw the current state of the game
 ***************************************************/
//void draw(const char* board, const Interface & ui, const set <int> & possible)
//{
//   ogstream gout;
//   
//   // draw the checkerboard
//   gout.drawBoard();
//
//   // draw any selections
//   gout.drawHover(ui.getHoverPosition());
//   gout.drawSelected(ui.getSelectPosition());
//
//   // draw the possible moves
//   set <int> :: iterator it;
//   for (it = possible.begin(); it != possible.end(); ++it)
//      gout.drawPossible(*it);
//
//   // draw the pieces
//   for (int i = 0; i < 64; i++)
//      switch (board[i])
//      {
//      case 'P':
//         gout.drawPawn(i, true);
//         break;
//      case 'p':
//         gout.drawPawn(i, false);
//         break;
//      case 'K':
//         gout.drawKing(i, true);
//         break;
//      case 'k':
//         gout.drawKing(i, false);
//         break;
//      case 'Q':
//         gout.drawQueen(i, true);
//         break;
//      case 'q':
//         gout.drawQueen(i, false);
//         break;
//      case 'R':
//         gout.drawRook(i, true);
//         break;
//      case 'r':
//         gout.drawRook(i, false);
//         break;
//      case 'B':
//         gout.drawBishop(i, true);
//         break;
//      case 'b':
//         gout.drawBishop(i, false);
//         break;
//      case 'N':
//         gout.drawKnight(i, true);
//         break;
//      case 'n':
//         gout.drawKnight(i, false);
//         break;
//      }
//}

/*********************************************
 * MOVE 
 * Execute one movement. Return TRUE if successful
 *********************************************/
//bool move(char* board, int positionFrom, int positionTo)
//{
//   // do not move if a move was not indicated
//   if (positionFrom == -1 || positionTo == -1)
//      return false;
//   assert(positionFrom >= 0 && positionFrom < 64);
//   assert(positionTo >= 0 && positionTo < 64);
//
//
//   // find the set of possible moves from our current location
//   set <int> possiblePrevious = getPossibleMoves(board, positionFrom);
//
//   // only move there is the suggested move is on the set of possible moves
//   if (possiblePrevious.find(positionTo) != possiblePrevious.end())
//   {
//      board[positionTo] = board[positionFrom];
//      board[positionFrom] = ' ';
//      return true;
//   }
//
//   return false;
//
//}

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(Interface *pUI, void * p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL. 
   Board* board = (Board*)p;
   ogstream gout;

   Position selectPosition = Position(pUI->getSelectPosition());
   Position hoverPosition = Position(pUI->getHoverPosition());
   Position previousPosition = Position(pUI->getPreviousPosition());

   // move
   Move move;

   //if (!previousPosition.isValid() && !selectPosition.isValid())
   //{
   //   if ((*board)[selectPosition].getLetter() == ' ')
   //      pUI->clearSelectPosition();
   //   else if ((*board)[selectPosition].isWhite() == board->whiteTurn())
   //      pUI->clearSelectPosition();
   //}


   if (previousPosition.isValid() && selectPosition.isValid())
   {
      move.setSrc(previousPosition);
      move.setDest(selectPosition);

      set<Move> possible = (*board)[previousPosition].getMoves(*board);

      auto it = possible.find(move);
      //if (it != possible.end())
      //   board.move(*it);

      pUI->clearSelectPosition();
      pUI->clearPreviousPosition();
   }

   board->display(hoverPosition, selectPosition);
}

/********************************************************
 * READ FILE
 * Read a file where moves are encoded in Smith notation
 *******************************************************/
//void readFile(const char* fileName, char* board)
//{
//   // open the file
//   ifstream fin(fileName);
//   if (fin.fail())
//      return;
//
//   // read the file, one move at a time
//   string textMove;
//   bool valid = true;
//   while (valid && fin >> textMove)
//   {
//      int positionFrom;
//      int positionTo;
//      parse(textMove, positionFrom, positionTo);
//      valid = move(board, positionFrom, positionTo);
//   }
//
//   // close and done
//   fin.close();
//}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   // run unit tests
   testRunner();

   Interface ui("Chess");    

   // Initialize the game class
   // note this is upside down: 0 row is at the bottom
   Board* board = new Board();
   
#ifdef _WIN32
 //  int    argc;
 //  LPWSTR * argv = CommandLineToArgvW(GetCommandLineW(), &argc);
 //  string filename = argv[1];
//   if (__argc == 2)
      /*readFile(__argv[1], board);*/
#else // !_WIN32
   if (argc == 2)
      readFile(argv[1], board);
#endif // !_WIN32

   // set everything into action
   ui.run(callBack, board);             

   return 0;
}
