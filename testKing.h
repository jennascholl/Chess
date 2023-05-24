/***********************************************************************
 * Header File:
 *    Test King : Test the King class
 * Author:
 *    Jenna Scholl
 * Summary:
 *    All the unit tests for King
 ************************************************************************/

#pragma once

#include "king.h"
#include "rook.h"
#include "pawn.h"
#include "space.h"
#include "board.h"

#include <cassert>

/********************************
* TEST KING
* A friend class for King which contains all its unit tests
********************************/
class TestKing
{
public:
   void run()
   {
      test_getMoves_free();
      test_getMoves_blocked();
      test_getMoves_capture();
      test_getMoves_castle_king_moved();
      test_getMoves_castle_rook_moved();
      test_getMoves_castle_blocked();
      test_getMoves_castle();
   }

private:
   /********************************
   * GET MOVES TEST - white king free
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 7                     7
   * 6                     6
   * 5         . . .       5
   * 4         . k .       4
   * 3         . . .       3
   * 2                     2
   * 1                     1
   * 0                     0
   * |                     |
   * +---0-1-2-3-4-5-6-7---+
   ********************************/
   void test_getMoves_free()
   {
      // setup
      King* k = new King();
      k->fWhite = true;
      k->lastMove = 0;
      k->numMoves = 0;
      k->position = Position(4, 4);

      Board* testBoard = new Board();
      testBoard->setToEmpty();
      testBoard->placePiece(k);
      
      //testBoard += k;

      // exercise
      set<Move> moves = k->getMoves(*testBoard);

      // verify
      assert(moves.size() == 8);
      assert(moves.find(Move("e5d6")) != moves.end());
      assert(moves.find(Move("e5e6")) != moves.end());
      assert(moves.find(Move("e5f6")) != moves.end());
      assert(moves.find(Move("e5d5")) != moves.end());
      assert(moves.find(Move("e5f5")) != moves.end());
      assert(moves.find(Move("e5d4")) != moves.end());
      assert(moves.find(Move("e5e4")) != moves.end());
      assert(moves.find(Move("e5f4")) != moves.end());
      assert(k->fWhite);
      assert(k->lastMove == 0);
      assert(k->numMoves == 0);
      assert(k->position == Position(4, 4));

      // teardown
      testBoard->free();
      delete testBoard;
   }

   /********************************
   * GET MOVES TEST - white king blocked
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8                     8
   * 7                     7
   * 6         p p p       6
   * 5         p k p       5
   * 4         p p p       4
   * 3                     3
   * 2                     2
   * 1                     1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ********************************/
   void test_getMoves_blocked()
   {
      // setup
      King* k = new King();
      k->fWhite = true;
      k->lastMove = 0;
      k->numMoves = 0;
      k->position = Position(5, 5);

      Board* testBoard = new Board();
      testBoard->setToEmpty();
      Pawn* p1 = new Pawn(Position(6, 4), true);
      Pawn* p2 = new Pawn(Position(6, 5), true);
      Pawn* p3 = new Pawn(Position(6, 6), true);
      Pawn* p4 = new Pawn(Position(5, 4), true);
      Pawn* p5 = new Pawn(Position(5, 6), true);
      Pawn* p6 = new Pawn(Position(4, 4), true);
      Pawn* p7 = new Pawn(Position(4, 5), true);
      Pawn* p8 = new Pawn(Position(4, 6), true);

      testBoard->placePiece(k);
      testBoard->placePiece(p1);
      testBoard->placePiece(p2);
      testBoard->placePiece(p3);
      testBoard->placePiece(p4);
      testBoard->placePiece(p5);
      testBoard->placePiece(p6);
      testBoard->placePiece(p7);
      testBoard->placePiece(p8);

      // exercise
      set<Move> moves = k->getMoves(*testBoard);

      // verify
      assert(moves.empty());
      assert(k->fWhite);
      assert(k->lastMove == 0);
      assert(k->numMoves == 0);
      assert(k->position == Position(5, 5));

      // teardown
      testBoard->free();
      delete testBoard;
   }

   /********************************
   * GET MOVES TEST - white king capture
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8                     8
   * 7                     7
   * 6         P P P       6
   * 5         P k P       5
   * 4         P P P       4
   * 3                     3
   * 2                     2
   * 1                     1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ********************************/
   void test_getMoves_capture()
   {
      // setup
      King* k = new King();
      k->fWhite = true;
      k->lastMove = 0;
      k->numMoves = 0;
      k->position = Position(4, 4);

      Board* testBoard = new Board();
      testBoard->setToEmpty();
      Pawn* p1 = new Pawn(Position(5, 3), false);
      Pawn* p2 = new Pawn(Position(5, 4), false);
      Pawn* p3 = new Pawn(Position(5, 5), false);
      Pawn* p4 = new Pawn(Position(4, 3), false);
      Pawn* p5 = new Pawn(Position(4, 5), false);
      Pawn* p6 = new Pawn(Position(3, 3), false);
      Pawn* p7 = new Pawn(Position(3, 4), false);
      Pawn* p8 = new Pawn(Position(3, 5), false);

      testBoard->placePiece(k);
      testBoard->placePiece(p1);
      testBoard->placePiece(p2);
      testBoard->placePiece(p3);
      testBoard->placePiece(p4);
      testBoard->placePiece(p5);
      testBoard->placePiece(p6);
      testBoard->placePiece(p7);
      testBoard->placePiece(p8);

      // exercise
      set<Move> moves = k->getMoves(*testBoard);

      // verify
      assert(moves.size() == 8);
      assert(moves.find(Move("e5d6p")) != moves.end());
      assert(moves.find(Move("e5e6p")) != moves.end());
      assert(moves.find(Move("e5f6p")) != moves.end());
      assert(moves.find(Move("e5d5p")) != moves.end());
      assert(moves.find(Move("e5f5p")) != moves.end());
      assert(moves.find(Move("e5d4p")) != moves.end());
      assert(moves.find(Move("e5e4p")) != moves.end());
      assert(moves.find(Move("e5f4p")) != moves.end());
      assert(k->fWhite);
      assert(k->lastMove == 0);
      assert(k->numMoves == 0);
      assert(k->position == Position(4, 4));

      // teardown
      testBoard->free();
      delete testBoard;
   }

   /********************************
   * GET MOVES TEST - white king castle (king moved)
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8                     8
   * 7                     7
   * 6                     6
   * 5                     5
   * 4                     4
   * 3                     3
   * 2         p p p       2
   * 1   r     . k .   r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ********************************/
   void test_getMoves_castle_king_moved()
   {
      // setup
      King* k = new King();
      k->fWhite = true;
      k->lastMove = 0;
      k->numMoves = 1;
      k->position = Position(0, 4);

      Board* testBoard = new Board();
      testBoard->setToEmpty();
      Pawn* p1 = new Pawn(Position(1, 3), true);
      Pawn* p2 = new Pawn(Position(1, 4), true);
      Pawn* p3 = new Pawn(Position(1, 5), true);
      Rook* r1 = new Rook(Position(0, 0), true);
      Rook* r2 = new Rook(Position(0, 7), true);

      testBoard->placePiece(k);
      testBoard->placePiece(p1);
      testBoard->placePiece(p2);
      testBoard->placePiece(p3);
      testBoard->placePiece(r1);
      testBoard->placePiece(r2);

      // exercise
      set<Move> moves = k->getMoves(*testBoard);

      // verify
      assert(moves.size() == 2);
      assert(moves.find(Move("e1f1")) != moves.end());
      assert(moves.find(Move("e1d1")) != moves.end());
      assert(k->fWhite);
      assert(k->lastMove == 0);
      assert(k->numMoves == 1);
      assert(k->position == Position(0, 4));

      // teardown
      testBoard->free();
      delete testBoard;
   }

   /********************************
   * GET MOVES TEST - white king castle (rook moved)
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8                     8
   * 7                     7
   * 6                     6
   * 5                     5
   * 4                     4
   * 3                     3
   * 2         p p p       2
   * 1   r     . k .   r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ********************************/
   void test_getMoves_castle_rook_moved()
   {
      // setup
      King* k = new King();
      k->fWhite = true;
      k->lastMove = 0;
      k->numMoves = 0;
      k->position = Position(0, 4);

      Board* testBoard = new Board();
      testBoard->setToEmpty();
      Pawn* p1 = new Pawn(Position(1, 3), true);
      Pawn* p2 = new Pawn(Position(1, 4), true);
      Pawn* p3 = new Pawn(Position(1, 5), true);
      Rook* r1 = new Rook(Position(0, 0), true);
      Rook* r2 = new Rook(Position(0, 7), true);
      r1->numMoves = 1;
      r2->numMoves = 1;

      testBoard->placePiece(k);
      testBoard->placePiece(p1);
      testBoard->placePiece(p2);
      testBoard->placePiece(p3);
      testBoard->placePiece(r1);
      testBoard->placePiece(r2);

      // exercise
      set<Move> moves = k->getMoves(*testBoard);

      // verify
      assert(moves.size() == 2);
      assert(moves.find(Move("e1f1")) != moves.end());
      assert(moves.find(Move("e1d1")) != moves.end());
      assert(k->fWhite);
      assert(k->lastMove == 0);
      assert(k->numMoves == 0);
      assert(k->position == Position(0, 4));

      // teardown
      testBoard->free();
      delete testBoard;
   }

   /********************************
   * GET MOVES TEST - white king castle (blocked)
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8                     8
   * 7                     7
   * 6                     6
   * 5                     5
   * 4                     4
   * 3                     3
   * 2         p p p       2
   * 1   r p   . k . p r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ********************************/
   void test_getMoves_castle_blocked()
   {
      // setup
      King* k = new King();
      k->fWhite = true;
      k->lastMove = 0;
      k->numMoves = 0;
      k->position = Position(0, 4);

      Board* testBoard = new Board();
      testBoard->setToEmpty();
      Pawn* p1 = new Pawn(Position(1, 3), true);
      Pawn* p2 = new Pawn(Position(1, 4), true);
      Pawn* p3 = new Pawn(Position(1, 5), true);
      Pawn* p4 = new Pawn(Position(0, 1), true);
      Pawn* p5 = new Pawn(Position(0, 6), true);
      Rook* r1 = new Rook(Position(0, 0), true);
      Rook* r2 = new Rook(Position(0, 7), true);

      testBoard->placePiece(k);
      testBoard->placePiece(p1);
      testBoard->placePiece(p2);
      testBoard->placePiece(p3);
      testBoard->placePiece(p4);
      testBoard->placePiece(p5);
      testBoard->placePiece(r1);
      testBoard->placePiece(r2);

      // exercise
      set<Move> moves = k->getMoves(*testBoard);

      // verify
      assert(moves.size() == 2);
      assert(moves.find(Move("e1f1")) != moves.end());
      assert(moves.find(Move("e1d1")) != moves.end());
      assert(k->fWhite);
      assert(k->lastMove == 0);
      assert(k->numMoves == 0);
      assert(k->position == Position(0, 4));

      // teardown
      testBoard->free();
      delete testBoard;
   }

   /********************************
   * GET MOVES TEST - white king castle
   * +---a-b-c-d-e-f-g-h---+
   * |                     |
   * 8                     8
   * 7                     7
   * 6                     6
   * 5                     5
   * 4                     4
   * 3                     3
   * 2         p p p       2
   * 1   r   . . k . . r   1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ********************************/
   void test_getMoves_castle()
   {
      // setup
      King* k = new King();
      k->fWhite = true;
      k->lastMove = 0;
      k->numMoves = 0;
      k->position = Position(0, 4);

      Board* testBoard = new Board();
      testBoard->setToEmpty();
      Pawn* p1 = new Pawn(Position(1, 3), true);
      Pawn* p2 = new Pawn(Position(1, 4), true);
      Pawn* p3 = new Pawn(Position(1, 5), true);
      Rook* r1 = new Rook(Position(0, 0), true);
      Rook* r2 = new Rook(Position(0, 7), true);

      testBoard->placePiece(k);
      testBoard->placePiece(p1);
      testBoard->placePiece(p2);
      testBoard->placePiece(p3);
      testBoard->placePiece(r1);
      testBoard->placePiece(r2);

      // exercise
      set<Move> moves = k->getMoves(*testBoard);

      // verify
      assert(moves.size() == 4);
      assert(moves.find(Move("e1f1")) != moves.end());
      assert(moves.find(Move("e1d1")) != moves.end());
      assert(moves.find(Move("e1g1c")) != moves.end());
      assert(moves.find(Move("e1c1C")) != moves.end());
      assert(k->fWhite);
      assert(k->lastMove == 0);
      assert(k->numMoves == 0);
      assert(k->position == Position(0, 4));

      // teardown
      testBoard->free();
      delete testBoard;
   }
};