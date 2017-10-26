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
  static const char obstacleBody = 176;
  static const char area = 32;
  int xCoordinate;
  int yCoordinate;
};
#endif // !OBSTACLES_H

