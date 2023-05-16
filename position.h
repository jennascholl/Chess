/***********************************************************************
 * Header File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich & Jenna Scholl
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/


#pragma once

#include <iostream>
using namespace std;

/*********************************************
 * DELTA
 * The possible directions of movement
 *********************************************/
struct Delta
{
   int x;
   int y;
   Delta(int r, int c) : x(r), y(c) { }
};

/*********************************************
* 7    0,  1,  2,  3,  4,  5,  6,  7,
* 6    8,  9, 10, 11, 12, 13, 14, 15,
* 5   16, 17, 18, 19, 20, 21, 22, 23,
* 4   24, 25, 26, 27, 28, 29, 30, 31,
* 3   32, 33, 34, 35, 36, 37, 38, 39,
* 2   40, 41, 42, 43, 44, 45, 46, 47,
* 1   48, 49, 50, 51, 52, 53, 54, 55,
* 0   56, 57, 58, 59, 60, 61, 62, 63
*      0   1   2   3   4   5   6   7
***********************************************/

/*********************************************
 * POSITION
 * A single position.
 *********************************************/
class Position
{
private:
   char location;

public:
   // constructors
   Position() : location(0) { }
   Position(int location);
   Position(int r, int c);
   Position(const Position& position, const Delta& delta) { set(position.getRow() + delta.y, position.getCol() + delta.x); }

   // getters
   const char getLocation() const { return location; }
   const char getRow() const { return 7 - (location / 8); }
   const char getCol() const { return location % 8; }

   //// setters
   void set(int r, int c);
   void set(int loc) { location = loc; }
   //void adjustRow(int dRow);
   //void adjustCol(int dCol);

   bool const isValid() const { return 0 <= location && location < 64; }
   bool operator==(Position rhs) { return location == rhs.location; }
   void operator=(Position rhs) { location = rhs.location; }
   // void operator+(Delta rhs);
};

// stream I/O useful for debugging
//std::ostream& operator << (std::ostream& out, const Position& pt);
//std::istream& operator >> (std::istream& in, Position& pt);


