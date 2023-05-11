/***********************************************************************
 * Header File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen.
 ************************************************************************/


#pragma once

#include <iostream>
using namespace std;

 /*********************************************
  * POINT
  * A single position.
  *********************************************/
class Position
{
private:
   int row;
   int col;

public:
   // constructors
   Position() : row(0), col(0) { }
	Position(int row, int col) : row(row), col(col) { }

   // getters
   //int getRow();
   //int getCol();

   //// setters
   //void setRow(int r);
   //void setCol(int c);
   //void set(int r, int c);
   //void adjustRow(int dRow);
   //void adjustCol(int dCol);

   //bool isValid();
   //bool operator==(Position rhs) { return location == rhs.location; }
   //void operator=(Position rhs);
   // void operator+(Delta rhs);
};

// stream I/O useful for debugging
std::ostream& operator << (std::ostream& out, const Position& pt);
std::istream& operator >> (std::istream& in, Position& pt);


