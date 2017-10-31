#ifndef OBSTACLES_H
#define OBSTACLES_H

#include "stdafx.h"

#include "Trace.h"

class Obstacles {
public:
  Obstacles(Trace& t);
  void drawObstacles();
  void next();

private:
  void clearArea();	

  Trace& trace_; 
  int xCoordinate_;
  int yCoordinate_;
};
#endif // !OBSTACLES_H

