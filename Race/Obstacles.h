#ifndef OBSTACLES_H
#define OBSTACLES_H

#include "stdafx.h"

#include <map>

#include "Trace.h"

using namespace std;

class Obstacles {
public:
  Obstacles(Trace& t);
  void drawObstacles();
  void next();

private:
  void clearArea();	
  Trace* trace; 
  int xCoordinate;
  int yCoordinate;
  static const int rightMargin = 3; //Indentation on the right, taking into account the wall of the route and the width of the obstacle
  static const int bottomMargin = 2;
 
};
#endif // !OBSTACLES_H

