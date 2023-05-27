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

   if (!previousPosition.isValid() && !selectPosition.isValid())
   {
      if ((*board)[selectPosition].getType() == SPACE)
         pUI->clearSelectPosition();
      else if ((*board)[selectPosition].isWhite() == board->whiteTurn())
         pUI->clearSelectPosition();
   }

   if (previousPosition.isValid() && selectPosition.isValid() && (*board)[previousPosition].isWhite() == board->whiteTurn())
   {
      Move move;
      move.setSrc(previousPosition);
      move.setDes(selectPosition);

      set<Move> possible = (*board)[previousPosition].getMoves(*board);

      // only move if it's on the list of possible moves
      auto it = possible.find(move);
      if (it != possible.end())
        board->move(*it);

      // reset selections
      pUI->clearSelectPosition();
      pUI->clearPreviousPosition();
   }

   board->display(hoverPosition, selectPosition);
}

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
