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
#include <cassert>

 // an empty board for testing purposes
Piece* EMPTY_BOARD[NUM_ROWS][NUM_COLS] =
{
   { &Space(Position(0, 0)), &Space(Position(0, 1)), &Space(Position(0, 2)), &Space(Position(0, 3)), &Space(Position(0, 4)), &Space(Position(0, 5)), &Space(Position(0, 6)), &Space(Position(0, 7)) },
   { &Space(Position(1, 0)), &Space(Position(1, 1)), &Space(Position(1, 2)), &Space(Position(1, 3)), &Space(Position(1, 4)), &Space(Position(1, 5)), &Space(Position(1, 6)), &Space(Position(1, 7)) },
   { &Space(Position(2, 0)), &Space(Position(2, 1)), &Space(Position(2, 2)), &Space(Position(2, 3)), &Space(Position(2, 4)), &Space(Position(2, 5)), &Space(Position(2, 6)), &Space(Position(2, 7)) },
   { &Space(Position(3, 0)), &Space(Position(3, 1)), &Space(Position(3, 2)), &Space(Position(3, 3)), &Space(Position(3, 4)), &Space(Position(3, 5)), &Space(Position(3, 6)), &Space(Position(3, 7)) },
   { &Space(Position(4, 0)), &Space(Position(4, 1)), &Space(Position(4, 2)), &Space(Position(4, 3)), &Space(Position(4, 4)), &Space(Position(4, 5)), &Space(Position(4, 6)), &Space(Position(4, 7)) },
   { &Space(Position(5, 0)), &Space(Position(5, 1)), &Space(Position(5, 2)), &Space(Position(5, 3)), &Space(Position(5, 4)), &Space(Position(5, 5)), &Space(Position(5, 6)), &Space(Position(5, 7)) },
   { &Space(Position(6, 0)), &Space(Position(6, 1)), &Space(Position(6, 2)), &Space(Position(6, 3)), &Space(Position(6, 4)), &Space(Position(6, 5)), &Space(Position(6, 6)), &Space(Position(6, 7)) },
   { &Space(Position(7, 0)), &Space(Position(7, 1)), &Space(Position(7, 2)), &Space(Position(7, 3)), &Space(Position(7, 4)), &Space(Position(7, 5)), &Space(Position(7, 6)), &Space(Position(7, 7)) } 
};

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
      test_getMoves_castle();
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
   * 8                     8
   * 7                     7
   * 6         . . .       6
   * 5         . k .       5
   * 4         . . .       4
   * 3                     3
   * 2                     2
   * 1                     1
   * |                     |
   * +---a-b-c-d-e-f-g-h---+
   ********************************/
   void test_getMoves_free()
   {
      // setup
      King* k;
      k->fWhite = true;
      k->lastMove = 0;
      k->numMoves = 0;
      k->position = Position(5, 5);

      Board* testBoard = new Board(EMPTY_BOARD);
      testBoard->placePiece(k);

      set <Move> expectedMoves = set<Move>
      {
         {Move(Position(5, 5), Position(6, 4))}, {Move(Position(5, 5), Position(6, 5))},
         {Move(Position(5, 5), Position(6, 6))}, {Move(Position(5, 5), Position(5, 4))},
         {Move(Position(5, 5), Position(5, 6))}, {Move(Position(5, 5), Position(4, 4))},
         {Move(Position(5, 5), Position(4, 5))}, {Move(Position(5, 5), Position(4, 6))}
      };

      // exercise
      set<Move> possibleMoves = k->getMoves(testBoard, Move());

      // verify
      assert(possibleMoves == expectedMoves);

      // teardown
      delete k;
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
      King* k;
      k->fWhite = true;
      k->lastMove = 0;
      k->numMoves = 0;
      k->position = Position(5, 5);

      Board* testBoard = new Board(EMPTY_BOARD);
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
      set<Move> possibleMoves = k->getMoves(testBoard, Move());

      // verify
      assert(possibleMoves.empty());

      // teardown
      delete k;
      delete p1;
      delete p2;
      delete p3;
      delete p4;
      delete p5;
      delete p6;
      delete p7;
      delete p8;
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
      King* k;
      k->fWhite = true;
      k->lastMove = 0;
      k->numMoves = 0;
      k->position = Position(5, 5);

      Board* testBoard = new Board(EMPTY_BOARD);
      Pawn* p1 = new Pawn(Position(6, 4), false);
      Pawn* p2 = new Pawn(Position(6, 5), false);
      Pawn* p3 = new Pawn(Position(6, 6), false);
      Pawn* p4 = new Pawn(Position(5, 4), false);
      Pawn* p5 = new Pawn(Position(5, 6), false);
      Pawn* p6 = new Pawn(Position(4, 4), false);
      Pawn* p7 = new Pawn(Position(4, 5), false);
      Pawn* p8 = new Pawn(Position(4, 6), false);

      testBoard->placePiece(k);
      testBoard->placePiece(p1);
      testBoard->placePiece(p2);
      testBoard->placePiece(p3);
      testBoard->placePiece(p4);
      testBoard->placePiece(p5);
      testBoard->placePiece(p6);
      testBoard->placePiece(p7);
      testBoard->placePiece(p8);

      set <Move> expectedMoves = set<Move>
      {
         {Move(Position(5, 5), Position(6, 4))}, {Move(Position(5, 5), Position(6, 5))},
         {Move(Position(5, 5), Position(6, 6))}, {Move(Position(5, 5), Position(5, 4))},
         {Move(Position(5, 5), Position(5, 6))}, {Move(Position(5, 5), Position(4, 4))},
         {Move(Position(5, 5), Position(4, 5))}, {Move(Position(5, 5), Position(4, 6))}
      };

      // exercise
      set<Move> possibleMoves = k->getMoves(testBoard, Move());

      // verify
      assert(possibleMoves == expectedMoves);

      // teardown
      delete k;
      delete p1;
      delete p2;
      delete p3;
      delete p4;
      delete p5;
      delete p6;
      delete p7;
      delete p8;
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
      King* k;
      k->fWhite = true;
      k->lastMove = 0;
      k->numMoves = 1;
      k->position = Position(1, 5);

      Board* testBoard = new Board(EMPTY_BOARD);
      Pawn* p1 = new Pawn(Position(2, 4), true);
      Pawn* p2 = new Pawn(Position(2, 5), true);
      Pawn* p3 = new Pawn(Position(2, 6), true);
      Rook* r1 = new Rook(Position(1, 1), true);
      Rook* r2 = new Rook(Position(1, 8), true);

      testBoard->placePiece(k);
      testBoard->placePiece(p1);
      testBoard->placePiece(p2);
      testBoard->placePiece(p3);
      testBoard->placePiece(r1);
      testBoard->placePiece(r2);

      set <Move> expectedMoves = set<Move>
      {
         {Move(Position(1, 5), Position(1, 4))}, {Move(Position(1, 5), Position(1, 6))}
      };

      // exercise
      set<Move> possibleMoves = k->getMoves(testBoard, Move());

      // verify
      assert(possibleMoves == expectedMoves);

      // teardown
      delete k;
      delete p1;
      delete p2;
      delete p3;
      delete r1;
      delete r2;
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
      King* k;
      k->fWhite = true;
      k->lastMove = 0;
      k->numMoves = 0;
      k->position = Position(1, 5);

      Board* testBoard = new Board(EMPTY_BOARD);
      Pawn* p1 = new Pawn(Position(2, 4), true);
      Pawn* p2 = new Pawn(Position(2, 5), true);
      Pawn* p3 = new Pawn(Position(2, 6), true);
      Rook* r1 = new Rook(Position(1, 1), true);
      Rook* r2 = new Rook(Position(1, 8), true);
      r1->numMoves = 1;
      r2->numMoves = 1;

      testBoard->placePiece(k);
      testBoard->placePiece(p1);
      testBoard->placePiece(p2);
      testBoard->placePiece(p3);
      testBoard->placePiece(r1);
      testBoard->placePiece(r2);

      set <Move> expectedMoves = set<Move>
      {
         {Move(Position(1, 5), Position(1, 4))}, {Move(Position(1, 5), Position(1, 6))}
      };

      // exercise
      set<Move> possibleMoves = k->getMoves(testBoard, Move());

      // verify
      assert(possibleMoves == expectedMoves);

      // teardown
      delete k;
      delete p1;
      delete p2;
      delete p3;
      delete r1;
      delete r2;
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
      King* k;
      k->fWhite = true;
      k->lastMove = 0;
      k->numMoves = 0;
      k->position = Position(1, 5);

      Board* testBoard = new Board(EMPTY_BOARD);
      Pawn* p1 = new Pawn(Position(2, 4), true);
      Pawn* p2 = new Pawn(Position(2, 5), true);
      Pawn* p3 = new Pawn(Position(2, 6), true);
      Pawn* p4 = new Pawn(Position(1, 2), true);
      Pawn* p5 = new Pawn(Position(1, 7), true);
      Rook* r1 = new Rook(Position(1, 1), true);
      Rook* r2 = new Rook(Position(1, 8), true);

      testBoard->placePiece(k);
      testBoard->placePiece(p1);
      testBoard->placePiece(p2);
      testBoard->placePiece(p3);
      testBoard->placePiece(p4);
      testBoard->placePiece(p5);
      testBoard->placePiece(r1);
      testBoard->placePiece(r2);

      set <Move> expectedMoves = set<Move>
      {
         {Move(Position(1, 5), Position(1, 4))}, {Move(Position(1, 5), Position(1, 6))}
      };

      // exercise
      set<Move> possibleMoves = k->getMoves(testBoard, Move());

      // verify
      assert(possibleMoves == expectedMoves);

      // teardown
      delete k;
      delete p1;
      delete p2;
      delete p3;
      delete p4;
      delete p5;
      delete r1;
      delete r2;
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
      King* k;
      k->fWhite = true;
      k->lastMove = 0;
      k->numMoves = 0;
      k->position = Position(1, 5);

      Board* testBoard = new Board(EMPTY_BOARD);
      Pawn* p1 = new Pawn(Position(2, 4), true);
      Pawn* p2 = new Pawn(Position(2, 5), true);
      Pawn* p3 = new Pawn(Position(2, 6), true);
      Rook* r1 = new Rook(Position(1, 1), true);
      Rook* r2 = new Rook(Position(1, 8), true);

      testBoard->placePiece(k);
      testBoard->placePiece(p1);
      testBoard->placePiece(p2);
      testBoard->placePiece(p3);
      testBoard->placePiece(r1);
      testBoard->placePiece(r2);


      Move castle1 = Move(Position(1, 5), Position(1, 3));
      Move castle2 = Move(Position(1, 5), Position(1, 7));
      castle1.setCastleQ();
      castle2.setCastleK();
      set <Move> expectedMoves = set<Move>
      {
         {Move(Position(1, 5), Position(1, 4))}, {Move(Position(1, 5), Position(1, 6))},
         {castle1}, {castle2}
      };

      // exercise
      set<Move> possibleMoves = k->getMoves(testBoard, Move());

      // verify
      assert(possibleMoves == expectedMoves);

      // teardown
      delete k;
      delete p1;
      delete p2;
      delete p3;
      delete r1;
      delete r2;
      testBoard->free();
      delete testBoard;
   }
};